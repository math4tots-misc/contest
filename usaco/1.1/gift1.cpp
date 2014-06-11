/*
ID: kyjkim1
TASK: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
	// istream& fin = cin; ostream& fout = cout; // for debug
	ifstream fin("gift1.in"); ofstream fout("gift1.out");
	
	int NP;
	vector<string> names; // ordered list of names
	map<string,int> money;
	fin >> NP;
	for (int i = 0; i < NP; i++) {
		string name;
		fin >> name;
		names.push_back(name);
		money[name] = 0;
	}
	for (int i = 0; i < NP; i++) {
		string giver;
		int total, NG, each;
		fin >> giver >> total >> NG;
		if (NG) {
			each = total / NG;
			for (int j = 0; j < NG; j++) {
				string taker;
				fin >> taker;
				money[taker] += each;
				money[giver] -= each;
			}
		}
	}
	for (int i = 0; i < NP; i++) {
		fout << names[i] << ' ' << money[names[i]] << endl;
	}
}
