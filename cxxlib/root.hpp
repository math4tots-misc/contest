/*

Tries to find the integer floor n-th root of x.

Makes a guess based on floating point arithmetic,
and then tries numbers around it to see if it would work.

If one couldn't be found returns -1.

----------------

root_limpow limits the exponent so that hopefully we don't overflow.

*/

template <class T, class R>
static inline T root_limpow(T r, R n, T m) {
	T t = 1;
	for (R i = 0; i < n; i++) {
		t *= r;
		if (t > m)
			return m+1;
	}
	return t;
}

template <class T, class R>
static inline T root(T x, R n) {
	T r = floor(pow(x,(double)1/n));
	for (T rr = r-1; rr <= r+1; rr++)
		if (root_limpow(rr,n,x) == x)
			return rr;
	return -1;
}
