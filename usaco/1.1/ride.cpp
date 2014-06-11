/*
ID: kyjkim1
TASK: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int calc(string s) {
	int p = 1;
	for (int i = 0; i < s.size(); i++) {
		p *= s[i] - 'A' + 1;
		p %= 47;
	}
	return p;
}

int main() {
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	// istream& fin = cin; // For debugging
	// ostream& fout = cout;
	
	string a, b;
	fin >> a >> b;
	
	fout << ((calc(a) == calc(b)) ? "GO" : "STAY") << endl;
}