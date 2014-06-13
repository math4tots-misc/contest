/*
ID: kyjkim1
LANG: C++
TASK: milk
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct Farmer {
	int P, A;
	bool operator<(const Farmer& f) const {
		return P < f.P || (P == f.P && A < f.A);
	}
};

istream& operator>>(istream& in, Farmer& f) {
	return in >> f.P >> f.A;
}

int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int N, M;
	fin >> N >> M;
	vector<Farmer> ff(M);
	for (int i = 0; i < M; i++) {
		fin >> ff[i];
	}
	sort(ff.begin(),ff.end());
	int t = 0;
	for (vector<Farmer>::iterator it = ff.begin(); it != ff.end(); it++) {
		int a = min(it->A, N);
		t += it->P * a;
		N -= a;
	}
	fout << t << endl;
}