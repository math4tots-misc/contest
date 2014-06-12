/*
ID: kyjkim1
LANG: C++
TASK: palsquare
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

static int B;

char i2c(int d) {
	return d < 10 ? '0' + d : 'A' + (d-10);
}

string i2s(int i) {
	string v;
	while (i) {
		v.push_back(i2c(i%B));
		i /= B;
	}
	reverse(v.begin(),v.end());
	return v;
}

bool is_palindrome(string s) {
	string r(s);
	reverse(r.begin(),r.end());
	return r == s;
}

int main() {
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	fin >> B;
	for (int N = 1; N <= 300; N++) {
		if (is_palindrome(i2s(N*N))) {
			fout << i2s(N) << ' ' << i2s(N*N) << endl;
		}
	}
}
