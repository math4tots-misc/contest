sieve = [true] * (10 ** 6)
sieve[0] = false
sieve[1] = false
(2...(sieve.size)).each do |i|
	next if !sieve[i]
	t = 2 * i
	while t < sieve.size
		sieve[t] = false
		t += i
	end
end

primes = sieve.each_with_index.select { |t,i| t }.map { |t,i| i }

gets.to_i.times do
	n = gets.to_i
	best = 1
	primes.each do |prime|
		if n%prime == 0
			best = prime if prime > best
			n /= prime while n%prime == 0
		end
	end
	best = n if n > best
	puts best
end
