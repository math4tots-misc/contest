/*
ID: kyjkim1
LANG: C++
TASK: calfflac
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

static string s;
static int best_size, best_start, best_end;

static void next(int& i, int dir) {
	do i += dir; while (0 <= i && i < s.size() && !isalpha(s[i]));
}

static bool match(int a, int b) {
	return toupper(s[a]) == toupper(s[b]);
}

static int find_size(int start, int end) {
	int size = 0;
	for (int i = start; i <= end; i++) {
		if (isalpha(s[i]))
			size++;
	}
	return size;
}

static void test(int start, int end) {
	while (start >= 0 && end < s.size() && match(start,end)) {
		next(start,-1);
		next(end,1);
	}
	next(start,1);
	next(end,-1);
	int size = find_size(start,end);
	if (size > best_size || (size == best_size && start < best_start)) {
		best_size = size;
		best_start = start;
		best_end = end;
	}
}

int main() {
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	stringstream ss;
	ss << fin.rdbuf();
	s = ss.str();
	for (int i = 0; i < s.size(); i++) {
		test(i,i);
		test(i,i+1);
	}
	fout << best_size << endl << 
		string(s.begin()+best_start,s.begin()+best_end+1) << endl;
}
