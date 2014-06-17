/*
ID: kyjkim1
LANG: C++
TASK: hamming
*/
#include <iostream>
#include <fstream>
using namespace std;

int N, B, D, a[1 << 8], *b=a;

// Pitfall I had here ....
// "distance" is already a reserved stl function
// causes problems b/c I am using namespace

int dist(int a, int b) {
	int d = 0;
	while (a || b) {
		if (a%2 ^ b%2)
			d++;
		a >>= 1;
		b >>= 1;
	}
	return d;
}

bool valid(int x) {
	for (int * i = a; i != b; i++)
		if (dist(x,*i) < D)
			return false;
	return true;
}

int main() {
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	fin >> N >> B >> D;
	
	for (int x = 0; x < 1 << B; x++)
		if (valid(x))
			*b++ = x;
	
	for (int *i = a; i-a < N; i++)
		fout << *i << ((i-a)%10 == 9 ? "\n" : i-a == N-1 ? "" : " ");
	
	cout << N << endl;
	
	if (N%10 != 0)
		fout << endl;
}