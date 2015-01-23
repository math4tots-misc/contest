#include <assert.h>
#include <stdio.h>
typedef long long ll;

static ll cache_stressfree[2001 * 2001], cache_stressful[2001 * 2001];

static int calculate_index(int a, int b) {
	return 2001 * a + b;
}

static ll stressfree(int a, int b) {
	int index = calculate_index(a, b);

	if (cache_stressfree[index] == -1)

		cache_stressfree[index] =
			(b == 0) ? 1 :
			(a == 0) ? 0 :
			(
				(
					((b > 0)   ? stressfree(a, b-1) : 0) +
					((a > b+1) ? stressfree(a-1, b) : 0)
				) % 1000000007LL
			);

	return cache_stressfree[index];
}

static ll stressful(int a, int b) {
	int index = calculate_index(a, b);

	if (cache_stressful[index] == -1)

		cache_stressful[index] =
			a  > b ? stressful(b, b) :
			a == 0 ? 1 :
			(
				(
					(b > a ? stressful(a, b-1) : 0) +
					(a > 0 ? stressful(a-1, b) : 0)
				) % 1000000007LL
			);

	return cache_stressful[index];
}

int main() {
	for (int i = 0; i < sizeof(cache_stressfree)/sizeof(ll); i++)
		cache_stressfree[i] = cache_stressful[i] = -1;

	assert(stressfree(2, 1) == 1);
	assert(stressful (2, 1) == 1);

	assert(stressfree(3, 1) == 2);
	assert(stressful (3, 1) == 1);

	assert(stressfree(3, 2) == 2);
	assert(stressful (3, 2) == 2);

	assert(stressfree(10, 5) == 1001);
	assert(stressful (10, 5) == 42);

	assert(stressfree(1000, 500) == 70047606);
	assert(stressful (1000, 500) == 591137401);

	for (int a = 0; a < 2001; a++) {
		for (int b = 0; b < 2001; b++) {
			stressfree(a, b);
			stressful(a, b);
		}
	}

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int a, b;
		scanf("%d-%d", &a, &b);
		printf("Case #%d: %lld %lld\n", t, stressfree(a, b), stressful(a, b));
	}
}
