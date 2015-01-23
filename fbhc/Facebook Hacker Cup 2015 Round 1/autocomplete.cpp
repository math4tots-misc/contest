#include <assert.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int length_of_longest_common_prefix(const string& a, const string& b) {
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		if (a[i] != b[i])
			return i;
	}
	return min(a.size(), b.size());
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		long long total = 0;
		set<string> seen;

		cin >> N;

		for (int i = 0; i < N; i++) {
			string s;
			int t = 1;
			cin >> s;
			auto r = seen.upper_bound(s);
			if (r != seen.end()) {
				t = 1+length_of_longest_common_prefix(s, *r);
			}
			if (r != seen.begin()) {
				r--;
				t = max(t, 1+length_of_longest_common_prefix(s, *r));
			}
			total += min<int>(s.size(), t);
			seen.insert(move(s));
		}
		cout << "Case #" << t << ": " << total << endl;
	}
}
