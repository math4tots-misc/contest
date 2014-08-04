// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have a vector <int> A with N elements.
// 
// Your goal is to change it into a vector <int> that contains each number from 1 to N exactly once. The change will consist of zero or more steps. In each step, you may pick an arbitrary element of A and increment its value by k. You may pick the same element multiple times. Note that you are not 
// allowed to decrement the value of any element.
// 
// You are given the int k and the vector <int> A.
// Return "POSSIBLE" if it is possible to achieve your goal. Return "IMPOSSIBLE" otherwise.
// 
// DEFINITION
// Class:IncrementingSequence
// Method:canItBeDone
// Parameters:int, vector <int>
// Returns:string
// Method signature:string canItBeDone(int k, vector <int> A)
// 
// 
// NOTES
// -Return value is case-sensitive. For example, you can't return "Possible" or "possible" instead of "POSSIBLE".
// 
// 
// CONSTRAINTS
// -k will be between 1 and 10, inclusive.
// -A will contain between 1 and 50 elements, inclusive.
// -Each element of A will be between 1 and 50, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// {1,2,4,3}
// 
// Returns: "POSSIBLE"
// 
// This sequence of length 4 already contains all numbers from 1 to 4 exactly once. Note that their order does not matter.
// 
// 1)
// 5
// {2,2}
// 
// Returns: "IMPOSSIBLE"
// 
// 
// 
// 2)
// 1
// {1,1,1,1,1,1,1,1}
// 
// Returns: "POSSIBLE"
// 
// There are many ways to achieve the goal. For example, it is possible to obtain the sequence {1,2,3,4,5,6,7,8}. To do this, just increment the element at each position one by one until it reaches the required value.
// 
// 3)
// 2
// {5,3,3,2,1}
// 
// Returns: "IMPOSSIBLE"
// 
// We want to have the values {1,2,3,4,5}, in any order. Currently, we are missing the 4. As k=2, the only way to produce a 4 is by incrementing a 2. But if we increment our only 2, we will have no way of producing another 2.
// 
// 4)
// 9
// {1,2,3,1,4,5,6,7,9,8}
// 
// Returns: "POSSIBLE"
// 
// 
// 
// 5)
// 2
// {1,1,1,1,1,1,2,2,2,2,2,2}
// 
// Returns: "POSSIBLE"
// 
// 
// 
// 6)
// 1
// {1}
// 
// Returns: "POSSIBLE"
// 
// 
// 
// END CUT HERE
#line 89 "IncrementingSequence.cpp"
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
class IncrementingSequence {
	public:
	string canItBeDone(int k, vector <int> A) {
		int N = A.size();
		vector<bool> bucket(N,false);
		for (int i = 0; i < N; i++) {
			int n = A[i];
			while (n <= N && bucket[n-1])
				n += k;
			if (n > N)
				return "IMPOSSIBLE";
			bucket[n-1] = true;
		}
		return "POSSIBLE";
	}
	// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1,2,4,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(0, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(1, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(2, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {5,3,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(3, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9; int Arr1[] = {1,2,3,1,4,5,6,7,9,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(4, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 2; int Arr1[] = {1,1,1,1,1,1,2,2,2,2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(5, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(6, Arg2, canItBeDone(Arg0, Arg1)); }

// END CUT HERE

	// END CUT HERE
};
// BEGIN CUT HERE
int main() {
	IncrementingSequence test;
	test.run_test(-1);
}
// END CUT HERE
