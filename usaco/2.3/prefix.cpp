/*
ID: kyjkim1
LANG: C++
TASK: prefix
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");
	vector<string> p; // primitives
	string s; // sequence
	
	fin >> s;
	while (s != ".") {
		p.push_back(s);
		fin >> s;
	}
	
	fin >> s;
	while (!fin.eof()) {
		string sa;
		fin >> sa;
		s += sa;
	}
	
	vector<bool> b(s.size()+1, false);
	b[0] = true;
	
	for (size_t i = 0; i < s.size(); i++) {
		if (b[i]) {
			for (vector<string>::iterator j = p.begin(); j != p.end(); ++j) {
				if (i+j->size() <= s.size() && s.compare(i,j->size(),*j) == 0) {
					b[i+j->size()] = true;
				}
			}
		}
	}
	
	for (int i = s.size(); i >= 0; i--) {
		if (b[i]) {
			fout << i << endl;
			break;
		}
	}
}