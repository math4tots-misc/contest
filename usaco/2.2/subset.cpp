/*
ID: kyjkim1
LANG: C++
TASK: subset
*/
#include <iostream>
#include <fstream>
using namespace std;

// test cases overflows 'int', so 'long long' is
// necessary here
static long long sums[800];

int main() {
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	
	int N;
	
	fin >> N;
	
	int total = (N * (N+1)) / 2;
	
	if (total%2 == 1)
		fout << 0 << endl;
	else {
		
		sums[0] = 1;
		for (int n = 1; n <= N; n++)
			for (int i = 799-n; i >= 0; i--)
				sums[i+n] += sums[i];
		
		fout << sums[total/2]/2 << endl;
	}
}