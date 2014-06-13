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