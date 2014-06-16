/*
ID: kyjkim1
LANG: C++
TASK: checker
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Board {
	vector<char> row;
	Board() : row(13) {}
	char& operator[](int i) { return row[i]; }
	bool operator< (const Board& b) const { return row <  b.row; }
	bool operator==(const Board& b) const { return row == b.row; }
};

static int N, number_of_solutions;
static bool placed_column[13], placed_left_diagonal[25], placed_right_diagonal[25];
static Board board, best[4];

ostream& operator<<(ostream& out, const Board& b) {
	out << (int) b.row[0] + 1;
	for (int i = 1; i < N; i++)
		out << ' ' << (int) b.row[i] + 1;
	return out;
}

static void place_queen(int row) {
	if (row == N) {
		best[min(3,number_of_solutions++)] = board;
		sort(best,best+min(4,number_of_solutions));
		return;
	}
	
	for (int column = 0; column < N; column++) {
		if (placed_column[column] ||
				placed_left_diagonal[row+column] ||
				placed_right_diagonal[N-1-column + row])
			continue;
		
		board[row] = column;
		placed_column[column] = 
			placed_left_diagonal[row+column] =
			placed_right_diagonal[N-1-column + row] = true;
			
		place_queen(row+1);
		
		placed_column[column] = 
			placed_left_diagonal[row+column] =
			placed_right_diagonal[N-1-column + row] = false;
	}
}

int main() {
	ifstream fin("checker.in");
	ofstream fout("checker.out");
	fin >> N;
	place_queen(0);
	for (int i = 0; i < 3; i++) {
		fout << best[i] << endl;
	}
	fout << number_of_solutions << endl;
}