// BEGIN CUT HERE
// PROBLEM STATEMENT
// Halina is a young mathematician.
// Recently she has been studying an interesting function h that operates on positive integers.
// 
// Let d(n) be the number of distinct positive divisors of n.
// The function h is then defined as follows: for each n we have h(n) = n^d(n).
// In words, h(n) is defined as n to the power of d(n).
// 
// For example, d(6)=4 because 6 is divisible by 1, 2, 3, and 6.
// Then, h(6) = 6^4 = 1296.
// 
// Halina already knows how to compute her function h.
// Now she would like to compute the inverse function.
// Help her!
// 
// You are given a long long n.
// Return the smallest x such that h(x) = n.
// If there is no such x, return -1 instead.
// 
// DEFINITION
// Class:DivisorsPower
// Method:findArgument
// Parameters:long long
// Returns:long long
// Method signature:long long findArgument(long long n)
// 
// 
// CONSTRAINTS
// -n will be between 2 and 10^18, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 4
// 
// Returns: 2
// 
// d(2) = 2, h(2) = 4
// 
// 1)
// 10
// 
// Returns: -1
// 
// There is no x satisfying h(x) = 10.
// 
// 2)
// 64
// 
// Returns: 4
// 
// d(4) = 3, h(4) = 64
// 
// 3)
// 10000
// 
// Returns: 10
// 
// d(10) = 4, h(10) = 10000
// 
// 4)
// 2498388559757689
// 
// Returns: 49983883
// 
// 
// 
// END CUT HERE
#line 72 "DivisorsPower.cpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <locale>
#include <bitset>
#include <functional>
#include <map>
#include <queue>
#include <streambuf>
#include <vector>
#include <complex>
#include <iomanip>
#include <iterator>
#include <set>
#include <string>
#include <deque>
#include <limits>
#include <sstream>
#include <utility>
#include <list>
#include <numeric>
#include <stack>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
class DivisorsPower {
	
	typedef long long LL;
	
	LL pow(LL x, LL n, LL b) {
		LL r = 1;
		while (n-- && r <= b)
			r *= x;
		return r;
	}
	
	// // Hmmm. Grader doesn't like this one. Possibly caused by overflow.
	// LL root(LL x, LL n) {
	// 	LL a = 0, b = x+1;
	// 	while (b - a > 1) {
	// 		LL c = (a+b) / 2;
	// 		if (pow(c, n, x+1) <= x) {
	// 			a = c;
	// 		} else {
	// 			b = c;
	// 		}
	// 	}
	// 	return a;
	// }
	
	LL root(LL x, LL n) {
		LL r = (LL) ::pow(x, 1.0/n);
		if (pow(r, n, x) == x)
			return r;
		if (pow(r+1, n, x) == x)
			return r+1;
		if (pow(r-1, n, x) == x)
			return r-1;
		return 0;
	}
	
	LL solve(LL x) {
		for (LL dn = 60; dn >= 2; dn--) {
			LL n = root(x, dn);
			if (pow(n, dn, x) == x && dn == num_divisors_of(n))
				return n;
		}
		return -1;
	}
	
	LL num_divisors_of(LL n) {
		LL i, nd = 0;
		for (i = 1; i*i < n; i++) {
			if (n%i == 0)
				nd += 2;
		}
		if (i*i == n)
			nd++;
		return nd;
	}
	
	public:
	long long findArgument(long long n) {
		return solve(n);
	}
	// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 2LL; verify_case(0, Arg1, findArgument(Arg0)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = -1LL; verify_case(1, Arg1, findArgument(Arg0)); }
	void test_case_2() { long long Arg0 = 64LL; long long Arg1 = 4LL; verify_case(2, Arg1, findArgument(Arg0)); }
	void test_case_3() { long long Arg0 = 10000LL; long long Arg1 = 10LL; verify_case(3, Arg1, findArgument(Arg0)); }
	void test_case_4() { long long Arg0 = 2498388559757689LL; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }

// END CUT HERE

	// END CUT HERE
};
// BEGIN CUT HERE
int main() {
	DivisorsPower test;
	test.run_test(-1);
}
// END CUT HERE
