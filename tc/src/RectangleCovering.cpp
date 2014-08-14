// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// There is a rectangular hole in the ground.
// You are given the dimensions of this rectangle: ints holeH and holeW.
// 
// 
// 
// You have a collection of rectangular boards.
// You are given their dimensions as two vector <int>s: boardH and boardW.
// For each valid i, you have a rectangular board with dimensions boardH[i] and boardW[i].
// You would like to cover the hole completely, using as few of these boards as possible.
// 
// 
// 
// There are some rules you must follow when covering the hole:
// 
// The boards may overlap arbitrarily.
// Together, the boards must cover the entire hole.
// You may rotate each board, but you must place it so that the sides of the board are parallel to the sides of the hole.
// All corners of each board must be strictly outside the hole. (That is, they are not allowed to lie on the boundary of the hole, either.)
// 
// 
// 
// 
// If you can cover the hole using the boards you have, return the smallest number of boards that is sufficient to cover the hole. Otherwise, return -1.
// 
// 
// DEFINITION
// Class:RectangleCovering
// Method:minimumNumber
// Parameters:int, int, vector <int>, vector <int>
// Returns:int
// Method signature:int minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW)
// 
// 
// CONSTRAINTS
// -holeH and holeW will be between 1 and 1,000,000,000, inclusive.
// -boardH and boardW will contain between 1 and 50 elements, inclusive.
// -boardH and boardW will contain the same number of elements.
// -Each element of boardH and boardW will be between 1 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 5
// 5
// {8,8,8}
// {2,3,4}
// 
// Returns: 2
// 
// You cannot cover this hole completely by using a single board. You can cover it by taking any two boards and placing them side by side.
// 
// 1)
// 10
// 10
// {6,6,6,6}
// {6,6,6,6}
// 
// Returns: -1
// 
// These four boards cannot be used to cover the hole. This is because of the rule that all board corners must be outside the hole.
// 
// 2)
// 5
// 5
// {5}
// {5}
// 
// Returns: -1
// 
// The corners of a board are not allowed to be on the boundary of the hole.
// 
// 3)
// 3
// 5
// {6}
// {4}
// 
// Returns: 1
// 
// 
// 
// 4)
// 10000
// 5000
// {12345,12343,12323,12424,1515,6666,6789,1424,11111,25}
// {1442,2448,42,1818,3535,3333,3456,7890,1,52}
// 
// Returns: 3
// 
// 
// 
// END CUT HERE
#line 98 "RectangleCovering.cpp"
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
class RectangleCovering {
	vector<int> h, w;
	
	int effective_length(int b, int d) {
		int l = 0;
		if (h[b] > d)
			l = w[b];
		if (w[b] > d)
			l = max(h[b],l);
		return l;
	}
	
	int needed(vector<int>& xs, int goal) {
		if (goal == 0)
			return 0;
		
		int cum = 0;
		for (int i = 0; i < xs.size(); i++) {
			cum += xs[i];
			if (cum >= goal)
				return i+1;
		}
		
		return -1;
	}
	
	public:
	int minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW) {
		h = boardH;
		w = boardW;
		
		vector<int> xx;
		for (int i = 0; i < h.size(); i++)
			xx.push_back(effective_length(i, holeH));
		sort(xx.begin(),xx.end());
		reverse(xx.begin(),xx.end());
		int a = needed(xx, holeW);
		
		vector<int> yy;
		for (int i = 0; i < h.size(); i++)
			yy.push_back(effective_length(i, holeW));
		sort(yy.begin(),yy.end());
		reverse(yy.begin(),yy.end());
		int b = needed(yy, holeH);
		
		if (a == -1)
			a = b;
		
		if (b == -1)
			b = a;
		
		return min(a,b);
	}
	// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {8,8,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,3,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {6,6,6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,6,6,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(2, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10000; int Arg1 = 5000; int Arr2[] = {12345,12343,12323,12424,1515,6666,6789,1424,11111,25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1442,2448,42,1818,3535,3333,3456,7890,1,52}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(4, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

	// END CUT HERE
};
// BEGIN CUT HERE
int main() {
	RectangleCovering test;
	test.run_test(-1);
}
// END CUT HERE
