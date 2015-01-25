template <class T>
vector<bool> prime_sieve(T N) {
	vector<bool> sieve(N+1, true);
	sieve[0] = sieve[1] = false;
	for (T i = 2; i <= N; i++)
		if (sieve[i])
			for (T j = i+i; j < N; j += i)
				sieve[j] = false;
	return move(sieve);
}

template <class T>
vector<T> primes_up_to(T N) {
	vector<bool> sieve(prime_sieve(N));
	vector<T> primes;
	for (T i = 2; i <= N; i++)
		if (sieve[i])
			primes.push_back(i);
	return move(primes);
}
