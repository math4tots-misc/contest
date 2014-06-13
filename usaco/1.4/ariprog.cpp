/*
ID: kyjkim1
LANG: C++
TASK: ariprog
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Seq {
	int a, b;
	bool operator<(const Seq& s) const {
		return b > s.b || (b == s.b && a > s.a);
	}
	bool operator==(const Seq& s) const {
		return a == s.a && b == s.b;
	}
};

int main() {
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	
	int N, M;
	bool bb[250 * 250 * 2 + 1];           // bb[i] is true iff i is a bisquare
	int bl[250 * 250 * 2 + 1], * be = bl; // bl[i] is i-th bisquare
	Seq ss[10000], * se = ss;             // array of valid sequences
	
	fin >> N >> M;
	
	// populate bb
	memset(bb,false,sizeof(bb));
	for (int p = 0; p <= M; p++)
		for (int q = 0; q <= M; q++)
			bb[p*p+q*q] = true;
	
	// populate bb/bc
	for (int i = 0; i <= M*M*2+1; i++)
		if (bb[i])
			*be++ = i;
	
	// search
	for (int * i = bl; i < be; i++) {
		int a = *i;
		for (int * j = i+1; j < be; j++) {
			int b = *j - a;
			if (a<b || !bb[a-b]) {
				int n = 2;
				
				while (a+n*b <= M*M*2 && bb[a+n*b])
					n++;
				
				int ta = a;
				while (n >= N) {
					se->a = ta;
					se->b = b;
					se++;
					ta += b;
					n--;
				}
			}
		}
	}
	
	// Sort and print the answers
	if (se == ss) {
		fout << "NONE" << endl;
	} else {
		sort(ss,se);
		while (se > ss) {
			se--;
			fout << se->a << ' ' << se->b << endl;
		}
	}
}