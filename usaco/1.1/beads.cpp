/*
ID: kyjkim1
LANG: C++
TASK: beads
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static int N;
static string b;

static int run(int i) {
	char t = 'w';
	int j = i;
	while (j < i+N) {
		if      (b[j] == 'w');
		else if (t    == 'w') t = b[j];
		else if (t    != b[j]) break;
		j++;
	}
	return j;
}

static void runs(vector<int>& rr) {
	for (int i = 0; i < N; i++)
		rr[i] = run(i) - i;
}

int main() {
	//istream& fin = cin; ostream& fout = cout;
	ifstream fin("beads.in"); ofstream fout("beads.out");
	fin >> N >> b;
	b = b + b;
	
	vector<int> left(N,0), right(N,0);
	
	runs(right);
	reverse(b.begin(), b.end());
	runs(left);
	reverse(left.begin(),left.end());
	
	int best = 0;
	for (int i = 0; i < N; i++) {
		int candidate = left[i] + right[(i+1)%N];
		if (candidate > best)
			best = candidate;
	}
	
	if (best > N)
		best = N;
	
	fout << best << endl;
}
