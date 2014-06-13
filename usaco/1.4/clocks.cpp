/*
ID: kyjkim1
LANG: C++
TASK: clocks
*/
#include <iostream>
#include <fstream>
using namespace std;

struct Counter {
	int x[9];
	bool valid;
	void operator++() {
		int i;
		for (i = 0; i < 9; i++)
			if (x[i] != 3)
				break;
		if (i == 9)
			valid = false;
		else {
			x[i--]++;
			while (i >= 0)
				x[i--] = 0;
		}
	}
};

struct Clocks {
	int x[9];
	void rotate(char c) {
		int i = c - 'A';
		x[i] += 3;
		if (x[i] == 15)
			x[i] = 3;
	}
	
	void rotate(string s) {
		for (string::iterator it = s.begin(); it != s.end(); it++)
			rotate(*it);
	}
	
	void move(int type) {
		rotate(
			(type == 1) ? "ABDE"   :
			(type == 2) ? "ABC"    :
			(type == 3) ? "BCEF"   :
			(type == 4) ? "ADG"    :
			(type == 5) ? "BDEFH"  :
			(type == 6) ? "CFI"    :
			(type == 7) ? "DEGH"   :
			(type == 8) ? "GHI"    :
			              "EFHI");
	}
	
	bool finished() const {
		for (int i = 0; i < 9; i++)
			if (x[i] != 12)
				return false;
		return true;
	}
	
	void apply(const Counter& ct) {
		for (int i = 1; i <= 9; i++)
			for (int j = 0; j < ct.x[i-1]; j++)
				move(i);
	}
};

int main() {
	ifstream fin("clocks.in");
	ofstream fout("clocks.out");
	
	Clocks cls;
	for (int i = 0; i < 9; i++)
		fin >> cls.x[i];
	
	Counter ct;
	ct.valid = true;
	for (int i = 0; i < 9; i++)
		ct.x[i] = 0;
	
	for (; ct.valid; ++ct) {
		Clocks copy = cls;
		copy.apply(ct);
		if (copy.finished())
			break;
	}
	
	bool first = true;
	for (int t = 1; t <= 9; t++) {
		for (int r = 0; r < ct.x[t-1]; r++) {
			if (!first)
				fout << ' ';
			fout << t;
			first = false;
		}
	}
	fout << endl;
}