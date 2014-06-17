/*
ID: kyjkim1
LANG: C++
TASK: sort3
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

static int N, n[1000], c[4], f[4][4], e;

static int region(int i) {
	return i < c[1] ? 1 :
		   i < c[2] ? 2 :
		              3 ;
}

int main() {
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	fin >> N;
	for (int i = 0; i < N; i++)
		fin >> n[i], c[n[i]]++;
	
	c[2] += c[1];
	c[3] += c[2];
	
	// step 0: keys already in place don't need to be bothered.
	
	// step 1: keys that are paired with each other's locations can be fixed
	// with one operation per pair of keys.
	
	for (int i = 0; i < N; i++)
		if (n[i] != region(i))
			f[region(i)][n[i]]++;
	
	e += min(f[1][2],f[2][1]);
	e += min(f[2][3],f[3][2]);
	e += min(f[1][3],f[3][1]);
	
	// step 2: we possibly have sets of cycles left 1 -> 2 -> 3 -> 1
	// These numbers must all match, and these sets may be handled with
	// 2 exchanges each.
	
	e += 2 * (max(f[1][2],f[2][1]) - min(f[1][2],f[2][1]));
	
	fout << e << endl;
}