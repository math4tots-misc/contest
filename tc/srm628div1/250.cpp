#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

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

template <class T>
static inline T ndiv(T x) {
	T t = 1;
	T d = 0;
	while (t*t < x) {
		if (x%t == 0)
			d += 2;
		t++;
	}
	if (t*t == x)
		d++;
	return d;
}

class DivisorsPower {
public:
	long long findArgument(long long x) {
		for (int d = 60; d >= 2; d--) {
			long long n = root(x,d);
			if (n != -1) {
				if (ndiv(n) == d) {
					return n;
				}
			}
		}
		return -1;
	}
};

