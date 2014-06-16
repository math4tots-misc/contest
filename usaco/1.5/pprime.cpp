/*
ID: kyjkim1
LANG: C++
TASK: pprime
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

static bool is_prime(long long x) {
	for (long long i = 2; i*i <= x; i++)
		if (x%i == 0)
			return false;
	return true;
}

int main() {
	vector<long long> palindromes;
	for (long long i = 1; i <= 100000; i++) {
		ostringstream oss;
		oss << i;
		string prefix = oss.str();
		string suffix = prefix;
		reverse(suffix.begin(),suffix.end());
		istringstream iss(prefix+suffix);
		long long ll;
		iss >> ll;
		palindromes.push_back(ll);
		prefix.erase(prefix.end()-1);
		istringstream iss2(prefix+suffix);
		iss2 >> ll;
		palindromes.push_back(ll);
	}
	sort(palindromes.begin(),palindromes.end());
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	long long a, b;
	fin >> a >> b;
	vector<long long>::iterator it = palindromes.begin();
	while (*it < a)
		it++;
	for (; it != palindromes.end(); it++) {
		if (*it > b)
			break;
		if (is_prime(*it))
			fout << *it << endl;
	}
}
