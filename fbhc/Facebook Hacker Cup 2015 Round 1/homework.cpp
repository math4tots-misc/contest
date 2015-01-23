#include <vector>
#include <iostream>
// #define NDEBUG
#include <assert.h>
#define N 10000000
using namespace std;

int main() {
	vector<bool> sieve(N+1, true);
	vector<int> primes;
	vector<int> primacy(N+1, 0);
	vector< vector<int> > cummulative_primacy(9, vector<int>(N+1, 0));
	int T, A, B, K;

	for (int i = 2; i <= N; i++) {
		if (sieve[i]) {
			for (int j = 2*i; j <= N; j += i) {
				sieve[j] = false;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (sieve[i]) {
			primes.push_back(i);
		}
	}

	assert(
		vector<int>({2, 3, 5, 7}) ==
		vector<int>(primes.begin(), primes.begin()+4));

	for (auto prime : primes) {
		for (int i = prime; i <= N; i += prime) {
			primacy[i]++;
		}
	}

	assert(primacy[2 * 2] == 1);
	assert(primacy[5]     == 1);
	assert(primacy[3 * 5] == 2);

	for (int k = 0; k < 9; k++) {
		for (int i = 1; i <= N; i++) {
			cummulative_primacy[k][i] =
				cummulative_primacy[k][i-1] +
				(primacy[i] == k ? 1 : 0);
		}
	}

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A >> B >> K;
		cout << "Case #" << i << ": " <<
			(K < 9 ?
				(cummulative_primacy[K][B] - cummulative_primacy[K][A-1]) :
				0) <<
			endl;
	}
}
