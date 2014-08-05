gets.to_i.times do
  n = gets.to_i
  n += 1
  r = 1
  sieve = Array.new(n,true)
  sieve[0] = sieve[1] = false
  (0...n).each do |i|
    if sieve[i]
      j = i
      j *= i while j * i < n
      r *= j
      
      j = i+i
      while j < n
        sieve[j] = false
        j += i
      end
    end
  end
  puts r
end

