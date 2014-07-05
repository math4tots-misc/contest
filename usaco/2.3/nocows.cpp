/*
ID: kyjkim1
LANG: C++
TASK: nocows
*/
#include <iostream>
#include <fstream>
using namespace std;

// x[n][k] is the number of pedigrees with n nodes whose height is AT MOST k.

int main() {
	int x[201][101];
	
	for (int n = 0; n < 201; n++)
		for (int k = 0; k < 101; k++)
			x[n][k] = 0;
	
	for (int k = 1; k <= 100; k++)
		x[1][k] = 1;
	
	for (int n = 2; n <= 200; n++)
		for (int k = 2; k <= 100; k++)
			for (int l = 1; l < n-1; l++)
				x[n][k] = (x[n][k] + x[l][k-1] * x[n-1-l][k-1]) % 9901;
	
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
	int N, K;
	fin >> N >> K;
	fout << (x[N][K] + 9901 - x[N][K-1])%9901 << endl;
}

// I don't think running time of this program should be affected by input.
// So the variation in running time between test cases is probably just noise.

// Test 1: TEST OK [0.038 secs, 3492 KB]
// Test 2: TEST OK [0.046 secs, 3492 KB]
// Test 3: TEST OK [0.019 secs, 3492 KB]
// Test 4: TEST OK [0.022 secs, 3492 KB]
// Test 5: TEST OK [0.038 secs, 3492 KB]
// Test 6: TEST OK [0.019 secs, 3492 KB]
// Test 7: TEST OK [0.038 secs, 3492 KB]
// Test 8: TEST OK [0.038 secs, 3492 KB]
// Test 9: TEST OK [0.038 secs, 3492 KB]
// Test 10: TEST OK [0.019 secs, 3492 KB]
// Test 11: TEST OK [0.043 secs, 3492 KB]
// Test 12: TEST OK [0.043 secs, 3492 KB]
