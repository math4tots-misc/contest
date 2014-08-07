// BEGIN CUT HERE
// PROBLEM STATEMENT
// Gustavo studies at the Byteversity (one of the best universities in Byteland). He's also very keen on dancing, so he decided to enroll at a dance school.
// 
// The school offers many different courses, each teaching one dance. Different courses may have different costs. You are given a vector <int> danceCost. The elements of danceCost are the costs of all courses offered at the dance school.
// 
// Gustavo would like to learn exactly K of those dances. He is a poor student, so his only priority is to pay as little as possible for the courses.
// 
// You are given the int K and the vector <int> danceCost. Compute and return the smallest possible total cost of learning K dances.
// 
// DEFINITION
// Class:CostOfDancing
// Method:minimum
// Parameters:int, vector <int>
// Returns:int
// Method signature:int minimum(int K, vector <int> danceCost)
// 
// 
// CONSTRAINTS
// -danceCost will contain between 1 and 1,000 elements, inclusive.
// -Each element of danceCost will be between 1 and 1,000, inclusive.
// -K will be between 1 and the number of elements in danceCost, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// {1, 5, 3, 4}
// 
// Returns: 4
// 
// Gustavo must pay for exactly two out of the four given courses. The cheapest possibility is to pay 1 for one course and then 3 for another course. The total cost is 1+3 = 4.
// 
// 1)
// 3
// {1, 5, 4}
// 
// Returns: 10
// 
// Gustavo has no choice here. He has to pay for all three courses, which costs 1+5+4 = 10.
// 
// 2)
// 1
// {2, 2, 4, 5, 3}
// 
// Returns: 2
// 
// Among all 5 possible courses he can take, the cheapest one is either the course #0 or course #1 (0-based).
// 
// 3)
// 39
// {973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932,
//  703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801}
// 
// Returns: 20431
// 
// 
// 
// END CUT HERE
#line 62 "CostOfDancing.cpp"
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
class CostOfDancing {
	public:
	int minimum(int K, vector <int> danceCost) {
		sort(danceCost.begin(),danceCost.end());
		int t = 0;
		for (int i = 0; i < K; i++)
			t += danceCost[i];
		return t;
	}
	// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1, 5, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, minimum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1, 5, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, minimum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {2, 2, 4, 5, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, minimum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 39; int Arr1[] = {973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932,
 703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20431; verify_case(3, Arg2, minimum(Arg0, Arg1)); }

// END CUT HERE

	// END CUT HERE
};
// BEGIN CUT HERE
int main() {
	CostOfDancing test;
	test.run_test(-1);
}
// END CUT HERE
