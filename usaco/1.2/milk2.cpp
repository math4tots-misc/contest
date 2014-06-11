/*
ID: kyjkim1
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Milking {
	int start, end;
	
	bool operator<(const Milking& other) const {
		return (start < other.start) || 
			(start == other.start && end < other.end);
	}
};

static istream& operator>>(istream& in, Milking& m) {
	return in >> m.start >> m.end;
}

int main() {
	//istream& fin = cin; ostream& fout = cout;
	ifstream fin("milk2.in"); ofstream fout("milk2.out");
	int N, start, end, milked = 0, idle = 0;
	fin >> N;
	vector<Milking> milkings(N);
	for (int i = 0; i < N; i++)
		fin >> milkings[i];
	
	sort(milkings.begin(),milkings.end());
	start = end = milkings[0].start;
	for (int i = 0; i < N; i++) {
		if (milkings[i].start <= end) {
			end = max(end,milkings[i].end);
			milked = max(milked,end-start);
		} else {
			start = milkings[i].start;
			idle = max(idle,start - end);
			end = milkings[i].end;
		}
	}
	
	fout << milked << ' ' << idle << endl;
}