// BEGIN CUT HERE
// PROBLEM STATEMENT
// Byteland is a city with many skyscrapers, so it's a perfect venue for BASE jumping. Danilo is an enthusiastic BASE jumper. He plans to come to Byteland and to jump off some of its buildings.
// 
// Danilo wants to make M jumps in Byteland. However, he has some rules. First, he never jumps off the same building twice. Second, all buildings he selects for his jumps must have the same number of floors. (This is for safety reasons: It is hard to get the timing right if each jump starts at a 
// different height.)
// 
// Philipe is the mayor of Byteland. He welcomes Danilo's visit as he would like to use it as a publicity stunt. However, Philipe knows that Danilo will only come to Byteland if there are at least M buildings that each have the same number of floors. To ensure that, the mayor is willing to build 
// additional floors on some of the skyscrapers in Byteland.
// 
// You are given the int M and a vector <int> heights. Each element of heights is the number of floors in one of Byteland's skyscrapers. Compute and return the smallest number of additional floors the mayor has to build so that there will be at least M buildings with the same number of floors.
// 
// DEFINITION
// Class:BuildingHeightsEasy
// Method:minimum
// Parameters:int, vector <int>
// Returns:int
// Method signature:int minimum(int M, vector <int> heights)
// 
// 
// CONSTRAINTS
// -heights will contain between 1 and 50 elements, inclusive.
// -M will be between 1 and the number of elements in heights, inclusive.
// -Each element in heights will be between 1 and 50, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// {1, 2, 1, 4, 3}
// 
// Returns: 0
// 
// Note that we already have two buildings that have the same number of floors. Hence, no additional floors need to be built.
// 
// 1)
// 3
// {1, 3, 5, 2, 1}
// 
// Returns: 2
// 
// We want to have at least three buildings with the same number of floors. The best way to reach this goal is to build one floor on building #0 and one floor on building #4 (0-based indices). After these changes, buildings #0, #3, and #4 will have two floors each.
// 
// 2)
// 1
// {43, 19, 15}
// 
// Returns: 0
// 
// 
// 
// 3)
// 3
// {19, 23, 9, 12}
// 
// Returns: 15
// 
// 
// 
// 4)
// 12
// {25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4}
// 
// Returns: 47
// 
// 
// 
// END CUT HERE
#line 71 "BuildingHeightsEasy.cpp"
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
class BuildingHeightsEasy {
	
	vector<int> hs;
	int M, H;
	
	int test(int h) {
		vector<int> v;
		for (int i = 0; i < H; i++) {
			if (hs[i] <= h)
				v.push_back(h - hs[i]);
		}
		if (v.size() < M)
			return -1;
		sort(v.begin(),v.end());
		int t = 0;
		for (int i = 0; i < M; i++) {
			t += v[i];
		}
		return t;
	}
	
	public:
	int minimum(int M, vector <int> heights) {
		this->M = M;
		H = heights.size();
		hs = heights;
		
		int b = -1;
		for (int h = 1; h <= 50; h++) {
			int r = test(h);
			if (b == -1 || (r != -1 && r < b)) {
				b = r;
			}
		}
		return b;
	}
	// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1, 2, 1, 4, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, minimum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1, 3, 5, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, minimum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {43, 19, 15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minimum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {19, 23, 9, 12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(3, Arg2, minimum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12; int Arr1[] = {25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; verify_case(4, Arg2, minimum(Arg0, Arg1)); }

// END CUT HERE

	// END CUT HERE
};
// BEGIN CUT HERE
int main() {
	BuildingHeightsEasy test;
	test.run_test(-1);
}
// END CUT HERE
