gets.to_i.times do
  n = gets.to_i
  s = (n*(n+1))/2
  q = (n*(2*n+1)*(n+1))/6
  puts s**2 - q
end
