/*
ID: kyjkim1
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// Names can be up to 12 digits long !!!!
// normal int's are going to overflow

long long char2int(char c) {
	switch(c) {
	case 'Q':
	case 'Z':
		return 0;
	
	default:
		if (c <= 'P') {
			return 2 + (c-'A')/3;
		} else {
			return 2 + ((c-1)-'A')/3;
		}
	}
}

long long name2int(string name) {
	long long i = 0;
	for (string::iterator it = name.begin(); it != name.end(); it++) {
		i *= 10;
		i += char2int(*it);
	}
	return i;
}

bool valid(long long i) {
	// 0's and 1's are not allowed.
	while (i) {
		switch(i%10) {
		case 0:
		case 1:
			return false;
		}
		i /= 10;
	}
	return true;
}

int main() {
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream din("dict.txt");
	long long N;
	bool none_found = true;
	fin >> N;
	string name;
	while (din >> name) {
		if (valid(name2int(name)) && name2int(name) == N) {
			none_found = false;
			fout << name << endl;
		}
	}
	if (none_found)
		fout << "NONE" << endl;
}