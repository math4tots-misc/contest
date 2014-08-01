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
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
class DivisorsPower {
	typedef long long LL;
	
	LL nd(LL n) {
		LL i = 0, d = 0;
		while (i*i < n) {
			if (n%i == 0) d += 2;
			i++;
		}
		if (i*i == n) d++;
		return d;
	}
	
	LL root(LL x, int d) {
		pow()
	}
	
	public:
	long long findArgument(long long x) {
		for (int d = 60; d >= 2; d--) {
			
		}
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
