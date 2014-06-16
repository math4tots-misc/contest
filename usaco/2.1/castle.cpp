/*
ID: kyjkim1
LANG: C++
TASK: castle
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

static int M, N, c[50][50], r[50][50], rc, rs[2500], b, bx, by;
static char d;
static bool v[50][50];

static void floodfill(int y, int x, int color) {
	if (!v[y][x]) {
		v[y][x] = true;
		r[y][x] = color;
		rs[color]++;
		if (!(c[y][x]&1))
			floodfill(y,x-1,color);
		if (!(c[y][x]&2))
			floodfill(y-1,x,color);
		if (!(c[y][x]&4))
			floodfill(y,x+1,color);
		if (!(c[y][x]&8))
			floodfill(y+1,x,color);
	}
}

int main() {
	ifstream fin("castle.in");
	ofstream fout("castle.out");
	fin >> M >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			fin >> c[y][x];
	
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (!v[y][x])
				floodfill(y,x,rc++);
	
	fout << rc << endl;
	fout << * max_element(rs,rs+rc) << endl;
	
	for (int x = M-1; x >= 0; x--) {
		for (int y = 0; y < N; y++) {
			if (x < M-1 && r[y][x] != r[y][x+1] && c[y][x]&4 && rs[r[y][x]]+rs[r[y][x+1]] >= b)
				b = rs[r[y][x]]+rs[r[y][x+1]], bx = x, by = y, d = 'E';
			
			if (y > 0   && r[y][x] != r[y-1][x] && c[y][x]&2 && rs[r[y][x]]+rs[r[y-1][x]] >= b)
				b = rs[r[y][x]]+rs[r[y-1][x]], bx = x, by = y, d = 'N';
		}
	}
	
	fout << b << endl;
	fout << by+1 << ' ' << bx+1 << ' ' << d << endl;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << r[y][x];
		} cout << endl;
	}
	cout << rs[0] << endl;
	cout << rs[1] << endl;
	cout << rs[2] << endl;
}
