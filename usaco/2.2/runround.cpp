/*
ID: kyjkim1
LANG: C++
TASK: runround
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
typedef long long LL;

bool is_runaround(LL x) {
	LL ds[9], d = 0;
	bool seen[10];
	
	// find all the digits of x
	for (LL i = 0; i < 10; i++)
		seen[i] = false;
	
	while (x) {
		
		if (x%10 == 0 || seen[x%10])
			return false;
		
		seen[x%10] = true;
		ds[d++] = x%10;
		x /= 10;
	}
	
	reverse(ds,ds+d);
	
	// follow the digits to see if x is really a runaround
	for (LL i = 0; i < d; i++)
		seen[i] = false;
	
	LL p = 0;
	for (LL c = 0; c < d; c++, p = (p+ds[p])%d) {
		if (seen[p])
			return false;
		seen[p] = true;
	}
	
	// remember that we must come back where we started,
	// i.e. we must have p == 0
	return p == 0;
}

int main() {
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	
	LL M;
	fin >> M;
	for (M++; !is_runaround(M); M++);
	fout << M << endl;
}