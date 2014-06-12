/*
ID: kyjkim1
LANG: C++
TASK: dualpal
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> i2v(int n, int base) {
	vector<int> v;
	while (n) {
		v.push_back(n%base);
		n /= base;
	}
	return v;
}

bool is_palindrome(int n, int base) {
	vector<int> v = i2v(n,base);
	vector<int> w = v;
	reverse(w.begin(),w.end());
	return v == w;
}

bool is_dualpal(int n) {
	int c = 0;
	for (int base = 2; base <= 10; base++) {
		c += is_palindrome(n,base);
	}
	return c >= 2;
}

int main() {
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int N, S;
	fin >> N >> S;
	while (N) {
		S++;
		if (is_dualpal(S)) {
			N--;
			fout << S << endl;
		}
	}
}
