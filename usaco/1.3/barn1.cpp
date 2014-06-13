/*
ID: kyjkim1
LANG: C++
TASK: barn1
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int M, S, C;
	fin >> M >> S >> C;
	vector<bool> stall(S,false);
	for (int i = 0; i < C; i++) {
		int p;
		fin >> p;
		stall[p-1] = true;
	}
	int start = 0, end = S;
	while (!stall[start]) start++;
	while (!stall[end-1]) end--;
	vector<int> runs;
	for (int i = start, last_cow = start-1; i < end; i++) {
		if (stall[i]) {
			if (i-last_cow > 1) {
				runs.push_back(i-last_cow-1);
			}
			last_cow = i;
		}
	}
	sort(runs.begin(),runs.end());
	int total = end - start;
	vector<int>::reverse_iterator it = runs.rbegin();
	for (int i = 1; i < M && it != runs.rend(); i++) {
		total -= *it;
		it++;
	}
	fout << total << endl;
}