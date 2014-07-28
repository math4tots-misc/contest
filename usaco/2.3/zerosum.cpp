/*
ID: kyjkim1
LANG: C++
TASK: zerosum
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int N;
char c[9];

int ev() {
	int a = 0, b = 0, p = 1;
	for (int i = N; i > 1; i--) {
		b += i * p;
		if (c[i-2] == ' ') {
			p *= 10;
		} else {
			if (c[i-2] == '+') a += b; else a -= b;
			b = 0;
			p = 1;
		}
	}
	return a + p + b;
}

void solve(int depth) {
	if (depth == N-1) {
		if (ev() == 0) {
			for (int i = 1; i < N; i++)
				fout << i << c[i-1];
			fout << N << endl;
		}
		return;
	}
	c[depth] = ' '; solve(depth+1);
	c[depth] = '+'; solve(depth+1);
	c[depth] = '-'; solve(depth+1);
}

int main() {
	fin >> N;
	solve(0);
}