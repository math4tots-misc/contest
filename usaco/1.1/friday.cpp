/*
ID: kyjkim1
LANG: C++
TASK: friday
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool is_leap_year(int year) {
	return (year%400 == 0) || (year%100 != 0 && year%4 == 0);
}

int days_in_month(int month, int year) {
	switch(month) {
		case 1: // february
			return 28 + is_leap_year(year);
		
		case 8: // september
		case 3: // april
		case 5: // june
		case 10: // november
			return 30;
		
		default:
			return 31;
	}
}

int main() {
	// istream& fin = cin; ostream& fout = cout; // debug
	ifstream fin("friday.in"); ofstream fout("friday.out");
	
	int x[7];
	for (int i = 0; i < 7; i++) {
		x[i] = 0;
	}
	
	int N;
	fin >> N;
	
	// we let 0 -> saturday for convenience when
	// printing the answer.
	
	// the first day we care about is January 13, 1900
	// Jan 8th, 1900 -> monday,
	// 9 -> tues
	// 10 -> wed
	// 11 -> thur
	// 12 -> fri
	// 13 -> saturday
	int day = 0;
	
	for (int year = 1900; year < 1900 + N; year++) {
		for (int month = 0; month < 12; month++) {
			x[day]++;
			day = (day + days_in_month(month,year)) % 7;
		}
	}
	
	for (int i = 0; i < 6; i++) {
		fout << x[i] << ' ';
	}
	fout << x[6] << endl;
}