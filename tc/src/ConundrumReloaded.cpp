// BEGIN CUT HERE
// PROBLEM STATEMENT
// Once upon a time, N people sat around a circle. They were numbered 0 through N-1 in counter-clockwise order. Each person was either a honest person or a liar. A honest person always tells the truth, a liar always lies. You asked some of them (possibly all or none) whether the person sitting to the 
// right of them is a liar. You are given their answers in a string answers with N characters. For each i, character i of answers is one of the following:
// 
// 
// 'L' if person i said that person (i+1) is a liar,
// 'H' if person i said that person (i+1) is a honest person,
// '?' if you didn't ask person i.
// 
// (Above, (i+1) is considered modulo N. That is, person N-1 is talking about person 0.)
// 
// You are given the string answers. If there is at least one possible combination of honest people and liars that is consistent with answers, return the smallest possible number of liars. Else return -1.
// 
// DEFINITION
// Class:ConundrumReloaded
// Method:minimumLiars
// Parameters:string
// Returns:int
// Method signature:int minimumLiars(string answers)
// 
// 
// CONSTRAINTS
// -answers will contain between 2 and 50 characters, inclusive.
// -Each character in answers will be 'L', 'H' or '?'.
// 
// 
// EXAMPLES
// 
// 0)
// "LLH"
// 
// Returns: 1
// 
// According to the input:
// 
// Person 0 says that person 1 is a liar.
// Person 1 says that person 2 is a liar.
// Person 2 says that person 0 is a honest person.
// 
// Clearly, they cannot all be honest, so there is at least one liar. It is possible that person 1 is liar and the other two are honest. Hence, the smallest possible number of liars is one.
// 
// (Note that it is also possible that person 1 is honest and the other two are liars.)
// 
// 1)
// "?????"
// 
// Returns: 0
// 
// Nobody told us anything. It is possible that everybody is honest.
// 
// 2)
// "LHLH?"
// 
// Returns: 2
// 
// If person #1 and person #2 are liars, then the answers would be "LHLHH". This is consistent with the answers we received.
// 
// 3)
// "??LLLLLL??"
// 
// Returns: 3
// 
// 
// 
// 4)
// "LLL"
// 
// Returns: -1
// 
// Each of the 8 possible combinations of (liar / honest person) will lead to a contradiction.
// 
// END CUT HERE
#line 75 "ConundrumReloaded.cpp"
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
class ConundrumReloaded {
	int N, G;
	string a;
	vector<int> g[2], V;
	
	int flip(int x) {
		return (x%2 == 0) ? x+1 : x-1;
	}
	
	int exp(char c, int x) {
		return (c == 'H') ? x : flip(x);
	}
	
	bool rec(int j) {
		int aa = V[j]/2, b = V[j]%2;
		g[b][aa]++;
		
		int i = (j-1+N)%N, k = (j+1)%N;
		if (V[i] != -1 && a[i] != '?' && exp(a[i],V[i]) != V[j])
			return false;
		if (V[i] == -1 && a[i] != '?') {
			V[i] = (exp(a[i],V[j]) == V[j]) ? V[j] : flip(V[j]);
			if (!rec(i))
				return false;
		}
		
		if (V[k] != -1 && a[j] != '?' && exp(a[j],V[j]) != V[k])
			return false;
		if (V[k] == -1 && a[j] != '?') {
			V[k] = exp(a[j],V[j]);
			if (!rec(k))
				return false;
		}
		
		return true;
	}
	
	public:
	int minimumLiars(string answers) {
		a = answers;
		N = a.size();
		G = 0;
		g[0].assign(N,0);
		g[1].assign(N,0);
		V.assign(N,-1);
		
		for (int i = 0; i < N; i++) {
			if (V[i] == -1) {
				V[i] = G++ * 2;
				if (!rec(i))
					return -1;
			}
		}
		
		int t = 0;
		for (int i = 0; i < G; i++) {
			t += min(g[0][i],g[1][i]);
		}
		return t;
	}
	// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLH"; int Arg1 = 1; verify_case(0, Arg1, minimumLiars(Arg0)); }
	void test_case_1() { string Arg0 = "?????"; int Arg1 = 0; verify_case(1, Arg1, minimumLiars(Arg0)); }
	void test_case_2() { string Arg0 = "LHLH?"; int Arg1 = 2; verify_case(2, Arg1, minimumLiars(Arg0)); }
	void test_case_3() { string Arg0 = "??LLLLLL??"; int Arg1 = 3; verify_case(3, Arg1, minimumLiars(Arg0)); }
	void test_case_4() { string Arg0 = "LLL"; int Arg1 = -1; verify_case(4, Arg1, minimumLiars(Arg0)); }

// END CUT HERE

	// END CUT HERE
};
// BEGIN CUT HERE
int main() {
	ConundrumReloaded test;
	test.run_test(-1);
}
// END CUT HERE
