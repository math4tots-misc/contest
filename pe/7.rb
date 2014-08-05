SIEVE = [true] * 1000000
SIEVE[0] = SIEVE[1] = false

(2...SIEVE.size).each do |i|
  j = i + i
  while j < SIEVE.size
    SIEVE[j] = false
    j += i
  end
end

PRIMES = []
(2...SIEVE.size).each do |i|
  PRIMES << i if SIEVE[i]
end

gets.to_i.times do
  n = gets.to_i
  puts PRIMES[n-1]
end

p PRIMES.take(3)
