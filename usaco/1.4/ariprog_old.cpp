/*
ID: kyjkim1
LANG: C++
TASK: ariprog
*/
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// With M = 250,
// there are only 21047 valid bisquares.
// So using brute force solution would be
// ~ 21047^2 * 25 ~ 11 billion.
// Might be a bit on the slow side,
// but still reasonable.
/*
int main() {
	int M = 250;
	set<int> bisquares;
	for (int p = 0; p <= M; p++) {
		for (int q = 0; q <= M; q++) {
			bisquares.insert(p*p + q*q);
		}
	}
	cout << bisquares.size() << endl;
}
*/

// Unfortunately brute force timed out at Run 7 with input
/*
21
200
*/

// So I could add a simple memoization technique.
// Unfortunately though, I'm not sure if it is going to be enough.

// In fact I don't think it's going to be enough.
// Simple test below shows even just finding every pair of differences
// is too slow.
/*
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	int M = 250;
	set<int> sbs;
	for (int p = 0; p <= M; p++) {
		for (int q = 0; q <= M; q++) {
			sbs.insert(p*p+q*q);
		}
	}
	vector<int> bs(sbs.begin(),sbs.end());
	cout << bs.size() << endl;
	set<int> sdifs;
	for (vector<int>::iterator x = bs.begin(); x != bs.end(); x++) {
		for (vector<int>::iterator y = x+1; y != bs.end(); y++) {
			sdifs.insert(*y - *x);
		}
	}
	cout << sdifs.size() << endl;
}
*/

// Solution must be linear in the number of bisquares.


static set<int> sbs;   // (ordered) set of bisquares
static vector<int> bs; // (ordered) vector of bisquares
static int N, M;

struct Seq {
	int a, b;
	Seq(int aa, int bb) : a(aa), b(bb) {}
	bool operator<(const Seq& s) const {
		return b < s.b || (b == s.b && a < s.a);
		// return a < s.a || (a == s.a && b < s.b);
	}
	bool operator==(const Seq& s) const { 
		return a == s.a && b == s.b;
	}
};

// Unmemoized

bool pass(int a, int b) {
	for (int n = 0; n < N; n++) {
		if (sbs.find(a+n*b) == sbs.end())
			return false;
	}
	return true;
}


int main() {
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	
	fin >> N >> M;
	
	for (int p = 0; p <= M; p++)
		for (int q = 0; q <= M; q++)
			sbs.insert(p*p + q*q);
	
	bs.assign(sbs.begin(),sbs.end());
	
	vector<Seq> ss;
	
	for (vector<int>::iterator i = bs.begin(); i != bs.end(); i++) {
		int a = *i;
		for (vector<int>::iterator j = i+1; j != bs.end(); j++) {
			int b = *j - a;
			if (pass(a,b))
				ss.push_back(Seq(a,b));
		}
	}
	
	if (ss.empty())
		fout << "NONE" << endl;
	else {
		sort(ss.begin(),ss.end());
		for (vector<Seq>::iterator i = ss.begin(); i != ss.end(); i++) {
			fout << i->a << ' ' << i->b << endl;
		}
	}
}