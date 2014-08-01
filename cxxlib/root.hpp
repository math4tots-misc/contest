/*

Tries to find the integer n-th root of x.

Makes a guess based on floating point arithmetic,
and then tries numbers around it to see if it would work.

If one couldn't be found returns -1.

----------------------

root_test returns true if r ** n == x and false otherwise.

*/

template <class T, class R>
static inline bool root_test(T r, R n, T x) {
	if (r == 0)
		return x == 0;
	for (R i = 0; i < n; i++)
		if (x%r == 0)
			x /= r;
		else
			return false;
	return x == 1;
}

template <class T, class R>
static inline T root(T x, R n) {
	T r = floor(pow(x,(double)1/n));
	for (T rr = r; rr <= r+1; rr++)
		if (root_test(rr,n,x))
			return rr;
	return -1;
}
