/*
ID: kyjkim1
LANG: C++
TASK: milk3
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

static int B[3]; // capacities of each bucket

struct Buckets {
	int b[3];
	Buckets(int a, int bb, int c) {
		b[0] = a;
		b[1] = bb;
		b[2] = c;
	}
	void pour(int src, int dest) {
		if (src != dest) {
			int amount = min(b[src],B[dest]-b[dest]);
			b[src]  -= amount;
			b[dest] += amount;
		}
	}
	bool operator<(const Buckets& r) const {
		for (int i = 0; i < 3; i++)
			if (b[i] < r.b[i])
				return true;
			else if (b[i] > r.b[i])
				return false;
		return false;
	}
	bool operator==(const Buckets& r) const {
		for (int i = 0; i < 3; i++)
			if (b[i] != r.b[i])
				return false;
		return true;
	}
};

int main() {
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	fin >> B[0] >> B[1] >> B[2];
	
	vector<Buckets> stack;
	set<Buckets> seen;
	bool possible[21];
	
	seen.insert(Buckets(0,0,B[2]));
	stack.push_back(Buckets(0,0,B[2]));
	while (!stack.empty()) {
		Buckets b = stack.back();
		stack.pop_back();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Buckets c = b;
				c.pour(i,j);
				if (seen.find(c) == seen.end()) {
					seen.insert(c);
					stack.push_back(c);
				}
			}
		}
	}
	
	memset(possible,false,sizeof(possible));
	for (set<Buckets>::iterator i = seen.begin(); i != seen.end(); ++i)
		if (i->b[0] == 0)
			possible[i->b[2]] = true;
	
	bool not_first = false;
	for (int i = 0; i < 21; i++) {
		if (possible[i]) {
			if (not_first)
				fout << ' ';
			fout << i;
			not_first = true;
		}
	}
	fout << endl;
}