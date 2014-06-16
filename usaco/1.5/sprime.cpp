/*
ID: kyjkim1
LANG: C++
TASK: sprime
*/
#include <iostream>
#include <fstream>
using namespace std;

static int c = 0, a[2][1000000] = { {2, 3, 5, 7} }, * b = a[0] + 4;
static const int d[] = { 1, 3, 7, 9 }, * e = d + 4;

static bool is_prime(int i) {
	for (int j = 2; j*j <= i; j++)
		if (i%j == 0)
			return false;
	return true;
}

static void next() {
	int *i, *j, f;
	for (i=&(a[c][0]), j=&(a[1-c][0]), f=10*(*i); i!=b; i++, f=10*(*i))
		for (const int * k = d; k != e; k++)
			if (is_prime(f+*k))
				*j++ = f+*k;
	b = j;
	c = 1 - c;
}

int main() {
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	int N;
	fin >> N;
	for (int i = 1; i < N; i++)
		next();
	for (int * i = a[c]; i != b; i++)
		fout << *i << endl;
}