/*
ID: kyjkim1
LANG: C++
TASK: numtri
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	int R;
	fin >> R;
	vector<int> v[2];
	v[0].resize(1);
	fin >> v[0][0];
	int c = 0;
	for (int i = 2; i <= R; i++) {
		c = 1 - c;
		v[c].resize(i);
		
		int x;
		fin >> x;
		v[c][0] = x + v[1-c][0];
		
		for (int j = 1; j < i-1; j++) {
			fin >> x;
			v[c][j] = x + max(v[1-c][j-1],v[1-c][j]);
		}
		
		fin >> x;
		v[c][i-1] = x + v[1-c][i-2];
	}
	fout << * max_element(v[c].begin(), v[c].end()) << endl;
}