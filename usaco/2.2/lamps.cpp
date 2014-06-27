/*
ID: kyjkim1
LANG: C++
TASK: lamps
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

static int N, C, on[101], * on_end = on, off[101], * off_end = off;

struct L;
ostream& operator<<(ostream& out, const L& l);

struct L {
	vector<bool> l;
	int number_of_button_presses;
	
	L(int x = 0) : l(N,true), number_of_button_presses(0) { configure(x); }
	
	void toggle(int i) { l[i] = 1 - l[i]; }
	
	void press1() {
		number_of_button_presses++;
		for (int i = 0; i < N; i++)
			toggle(i);
	}
	
	void press2() {
		number_of_button_presses++;
		for (int i = 0; i < N; i += 2)
			toggle(i);
	}
	
	void press3() {
		number_of_button_presses++;
		for (int i = 1; i < N; i += 2)
			toggle(i);
	}
	
	void press4() {
		number_of_button_presses++;
		for (int i = 0; i < N; i += 3)
			toggle(i);
	}
	
	void configure(int x) {
		if (x%2)
			press1();
		
		if ((x/2)%2)
			press2();
		
		if ((x/4)%2)
			press3();
		
		if ((x/8)%2)
			press4();
	}
	
	int number_of_ones() const {
		int c = 0;
		for (int i = 0; i < N; i++)
			if (l[i])
				c++;
		return c;
	}
	
	void reset() { l.assign(N,true); }
	bool operator< (const L& x) const { return l <  x.l; }
	bool operator==(const L& x) const { return l == x.l; }
	
	bool valid() const  {
		for (int * i = on; i != on_end; i++)
			if (!l[*i])
				return false;
		
		for (int * i = off; i != off_end; i++)
			if (l[*i])
				return false;
		
		int c = number_of_button_presses;
		
		return (c <= C) && ((C-c)%2 == 0);
	}
};

ostream& operator<<(ostream& out, const L& l) {
	for (vector<bool>::const_iterator it = l.l.begin(); it != l.l.end(); ++it)
		out << *it;
	return out;
}

int main() {
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");
	
	fin >> N >> C;
	do fin >> *on_end++;  while (*(on_end -1) != -1); on_end--;
	do fin >> *off_end++; while (*(off_end-1) != -1); off_end--;
	
	for (int * p = on; p != on_end; ++p)
		(*p)--;
	
	for (int * p = off; p != off_end; ++p)
		(*p)--;
	
	set<L> a;
	
	for (int i = 0; i < 16; i++)
		if (L(i).valid())
			a.insert(L(i));
	
	if (a.size() == 0)
		fout << "IMPOSSIBLE" << endl;
	else
		for (set<L>::const_iterator i = a.begin(); i != a.end(); ++i)
			fout << *i << endl;
}
