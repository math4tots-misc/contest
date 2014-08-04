/*
Counts the number of divisors of x
*/

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
