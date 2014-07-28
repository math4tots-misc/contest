#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class BubbleSortWithReversals {
private:	
	
	int N, original_swap_count, swap_modifier[51][51], memo[51][51];
	
	int solve(const int i, const int K) {
		if (memo[i][K] == -1) {
			int min_swaps = original_swap_count;
			for (int j = i+2; j <= N; j++) {
				int best_modifier = 0;
				for (int k = i; k < j; k++)
					best_modifier = min(best_modifier,swap_modifier[k][j]);
				min_swaps = min(min_swaps,best_modifier+solve(j,K-1));
			}
			memo[i][K] = min_swaps;
		}
		return memo[i][K];
	}
	
public:
	int getMinSwaps(vector<int> A, int K) {
		N = A.size();
		
		// populate swap_modifier
		fill(
			&swap_modifier[0][0],
			&swap_modifier[0][0] +
				sizeof(swap_modifier) / sizeof(swap_modifier[0][0]),
			0);
		for (int i = 0; i < N; i++)
			for (int j = i+2; j <= N; j++)
				for (int k = i; k < j; k++)
					for (int l = k+1; l < j; l++)
						if (A[k] < A[l])
							swap_modifier[i][j]++;
						else if (A[k] > A[l])
							swap_modifier[i][j]--;
		
		// calculate original_swap_count
		original_swap_count = 0;
		for (int j = 0; j < N-1; j++)
			for (int i = 0; i < N-1; i++)
				if (A[i] > A[i+1])
					swap(A[i],A[i+1]), original_swap_count++;
		
		// initialize memo
		fill(
			&memo[0][0],
			&memo[0][0] +
				sizeof(memo) / sizeof(memo[0][0]),
			-1);
		for (int i = 0; i <= N; i++)
			memo[i][0] = original_swap_count;
		for (int k = 0; k <= K; k++)
			memo[N][k] = original_swap_count;
		return solve(0,K);
	}
};

int main() {
	BubbleSortWithReversals b;
	vector<int> A(50);
	for (int i = 0; i < 50; i++)
		A[i] = 51-i;
	int K = 1;
	cout << b.getMinSwaps(A,K) << endl;
	return 0;
}