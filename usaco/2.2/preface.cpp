/*
ID: kyjkim1
LANG: C++
TASK: preface
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

string n[] = {"I", "V", "X", "L", "C", "D", "M", "", ""};
map<char,int> used;

string repeat(string s, int t) {
	string r;
	for (; t; t--)
		r += s;
	return r;
}

string convert10(string one, string five, string ten, int d) {
	switch(d) {
	case 1:
	case 2:
	case 3:
		return repeat(one,d);
	
	case 4:
		return one + five;
	
	case 5:
	case 6:
	case 7:
	case 8:
		return five + repeat(one,(d-5));
	
	case 9:
		return one + ten;
	}
	return "";
}

string convert(int x) {
	string r;
	for (int i = 0; x && i < 7; i += 2) {
		r  = convert10(n[i],n[i+1],n[i+2],x%10) + r;
		x /= 10;
	}
	return r;
}

int main() {
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	for (int i = 0; i < 7; i++)
		used[n[i][0]] = 0;
	
	int N;
	
	fin >> N;
	
	for (int i = 1; i <= N; i++) {
		string s = convert(i);
		for (string::iterator it = s.begin(); it != s.end(); it++)
			used[*it]++;
	}
	
	for (int i = 0; used[n[i][0]] && i < 7; i++)
		fout << n[i] << ' ' << used[n[i][0]] << endl;
}
