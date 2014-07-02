// https://www.hackerrank.com/challenges/two-arrays
/*
I actually solved this one already with haskell (two_arrays.hs).
Just wanted to see performance difference.

Perhaps I am just a lot more comfortable with C++, but this C++ version
was much easier to write. At least the I/O part of it anyway.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	
	cin >> T;
	
	while (T--) {
		int N, K, a[1000], b[1000];
		bool possible = true;
		
		cin >> N >> K;
		
		for (int i = 0; i < N; i++)
			cin >> a[i];
		
		for (int i = 0; i < N; i++)
			cin >> b[i];
		
		sort(a,a+N);
		sort(b,b+N);
		reverse(b,b+N);
		
		for (int i = 0; i < N; i++)
			if (a[i]+b[i] < K)
				possible = false;
			
		cout << (possible ? "YES" : "NO") << endl;
	}
}
/*
# 0  0.02s : Success 
# 1  0.02s : Success 
# 2  0.02s : Success 
# 3  0.02s : Success 
# 4  0.02s : Success 
# 5  0.02s : Success 
# 6  0.02s : Success 
# 7  0.02s : Success 
# 8  0.02s : Success 
# 9  0.02s : Success 

So yea. It looks like C++ version is faster. Although these tests run so fast
that it is hard to say even by what order of magnitude.

But I realized my original Haskell version used Integer instead of Int.

It's possible that using arbitrary precision integers might slow things down.

However, I reran the tests with Integer changed to Int (see two_arrays.hs).

Turns out it still has noticeable runtime differences.


I mean semantically speaking, the Haskell version is bound to take a hit for
keeping everything immutable and using linkedlists everywhere instead of
mutable arrays.

Or it could just be my Haskell noobieness.

*/

