/*
ID: kyjkim1
LANG: C++
TASK: transform
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

static int N;

struct Grid {
	vector< vector<char> > x;
	
	Grid rotate90() {
		Grid g;
		for (int i = 0; i < N; i++) {
			g.x.push_back(vector<char>());
			for (int j = 0; j < N; j++) {
				g.x[i].push_back(x[N-1-j][i]);
			}
		}
		return g;
	}
	
	Grid rotate180() {
		return rotate90().rotate90();
	}
	
	Grid rotate270() {
		return rotate180().rotate90();
	}
	
	Grid reflect() {
		Grid g;
		for (int i = 0; i < N; i++) {
			g.x.push_back(vector<char>());
			for (int j = 0; j < N; j++) {
				g.x[i].push_back(x[i][N-1-j]);
			}
		}
		return g;
	}
	
	bool operator==(const Grid& other) {
		return x == other.x;
	}
};

istream& operator>>(istream& in, Grid& g) {
	for (int i = 0; i < N; i++) {
		string line;
		in >> line;
		g.x.push_back(vector<char>(line.begin(),line.end()));
	}
	return in;
}

int main() {
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	Grid g, h;
	fin >> N >> g >> h;
	fout << (
		h == g.rotate90()  ? 1 :
		h == g.rotate180() ? 2 :
		h == g.rotate270() ? 3 :
		h == g.reflect()   ? 4 :
		h == g.reflect().rotate90() ||
			h == g.reflect().rotate180() || 
			h == g.reflect().rotate270() ? 5 :
		h == g ? 6 :
		7
	) << endl;
}