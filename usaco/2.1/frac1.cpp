/*
ID: kyjkim1
LANG: C++
TASK: frac1
*/


/*

My C++ solution below is completely straight forward.

However, the analysis section has a super cool simple solution based on
a super cool property of fractions -- I just couldn't resist the temptation
to include a mention here:
"""
Here's a super fast solution from Russ:

We notice that we can start with 0/1 and 1/1 as our ``endpoints'' and recursively generate the middle points by adding numerators and denominators.

0/1                                                              1/1
                               1/2
                  1/3                      2/3
        1/4              2/5         3/5                 3/4
    1/5      2/7     3/8    3/7   4/7   5/8       5/7         4/5
Each fraction is created from the one up to its right and the one up to its left. This idea lends itself easily to a recursion that we cut off when we go too deep.

"""

For a clarification of the above,

Notice 1/2 = (0+1)/(1+1)
       1/3 = (0+1)/(1+2)
       1/4 = (0+1)/(1+3)
       ...
       5/7 = (2+3)/(3+4) (i.e. from 2/3 and 3/4)
       ...

That is, given a/b and c/d, (a+c)/(b+d) is a fraction in between them.

Although the problem doesn't seem to mention it explicitly, for some other cool
properties of sequences of fractions like this, the wikipedia page on
Farey sequences is worth a look: http://en.wikipedia.org/wiki/Farey_sequence

*/

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

struct F {
	unsigned int n, d;
	F(unsigned int n, unsigned int d) {
		int g = gcd(n,d);
		this->n = n/g;
		this->d = d/g;
	}
	bool operator< (const F& f) const { return n*f.d <  f.n*d; }
	bool operator==(const F& f) const { return n*f.d == f.n*d; }
	
	static int gcd(unsigned int a, unsigned int b) {
		while (b) {
			unsigned int t = b;
			b = a%b;
			a = t;
		}
		return a;
	}
};

ostream& operator<<(ostream& out, const F& f) {
	return out << f.n << '/' << f.d;
}

int main() {
	unsigned int N;
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	fin >> N;
	
	set<F> fs;
	for (unsigned int d = 1; d <= N; d++)
		for (unsigned int n = 0; n <= d; n++)
			fs.insert(F(n,d));
	
	for (set<F>::iterator i = fs.begin(); i != fs.end(); i++)
		fout << *i << endl;
}