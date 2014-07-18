#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAX_N 200000000

static bool happiness_cache[11][MAX_N], cached[11][MAX_N];

static inline int sum_of_square_digits(int n, int b) {
	int m = 0;
	while (n) {
		m += (n%b) * (n%b);
		n /= b;
	}
	return m;
}

static inline bool calculate_happiness(int n, int b) {
	set<int> s;
	while (n != 1 && s.find(n) == s.end()) {
		s.insert(n);
		n = sum_of_square_digits(n,b);
	}
	return n == 1;
}

static inline void init() {
	for (int b = 2; b < 11; b++) {
		happiness_cache[b][1] = true;
		cached[b][n] = true;
		for (int n = 2; n < 1000; n++) {
			happiness_cache[b][n] = calculate_happiness(n);
			cached[b][n] = true;
		}
	}
}

static inline bool happy(int n, int b) {
	if (!cached[b][n]) {
		happiness_cache[b][n] = happy(sum_of_square_digits(n,b),b);
		cached[b][n] = true;
	}
	return happiness_cache[b][n];
}

int main() {
	init();
	
}