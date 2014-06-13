/*
ID: kyjkim1
LANG: C++
TASK: crypt1
*/
#include <iostream>
#include <fstream>
using namespace std;

bool digits[10];

static bool check(int x, int num_digits) {
	while (num_digits) {
		if (!digits[x%10])
			return false;
		x /= 10;
		num_digits--;
	}
	return x == 0;
}

static bool check_pair(int a, int b) {
	return check(a,3) &&
		check(b,2) && 
		check(a*(b%10),3) && 
		check(a*(b/10),3) &&
		check(a*b,4);
}

int main() {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	for (int i = 0; i < 10; i++)
		digits[i] = false;
	int N;
	fin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		fin >> x;
		digits[x] = true;
	}
	int nsol = 0;
	for (int a = 0; a < 1000; a++) {
		for (int b = 0; b < 100; b++) {
			nsol += check_pair(a,b);
		}
	}
	fout << nsol << endl;
}