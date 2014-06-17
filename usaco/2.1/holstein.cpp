/*
ID: kyjkim1
LANG: C++
TASK: holstein
*/
#include <iostream>
#include <fstream>
using namespace std;

static int V, v[25], G, g[15][25];
static bool found;

struct S {
	bool sg[15];
	int sv[25], c;
	bool operator<(const S& s) const {
		if (c != s.c)
			return c < s.c;
		
		for (int i = 0; i < G; i++)
			if (sg[i] != s.sg[i])
				return sg[i] > s.sg[i];
		
		return false;
	}
	void on(int i) {
		if (!sg[i]) {
			c++;
			sg[i] = true;
			for (int j = 0; j < V; j++)
				sv[j] += g[i][j];
		}
	}
	void off(int i) {
		if (sg[i]) {
			c--;
			sg[i] = false;
			for (int j = 0; j < V; j++)
				sv[j] -= g[i][j];
		}
	}
	bool happy() {
		for (int i = 0; i < V; i++)
			if (sv[i] < v[i])
				return false;
		return true;
	}
};

static S s, b;

void recurse(int gi) {
	if (s.happy()) {
		if (!found || s < b)
			found = true, b = s;
		return;
	}
	
	if (gi == G)
		return;
	
	recurse(gi+1);
	s.on(gi);
	recurse(gi+1);
	s.off(gi);
}

int main() {
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	fin >> V;
	for (int i = 0; i < V; i++)
		fin >> v[i];
	fin >> G;
	for (int i = 0; i < G; i++)
		for (int j = 0; j < V; j++)
			fin >> g[i][j];
	
	recurse(0);
	
	fout << b.c;
	for (int i = 0; i < G; i++)
		if (b.sg[i])
			fout << ' ' << i+1;
	fout << endl;
}