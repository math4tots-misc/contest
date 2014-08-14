# A[0], A[1]
# B[0], B[1]
# A[0] == gcd(B[0],B[1])

def gcd(a, b)
  a, b = b, a%b while b != 0
  return a
end

def lcm(a, b)
  return a * b / gcd(a,b)
end

gets.to_i.times do
  n = gets.to_i
  a = gets.split.map { |i| i.to_i }
  b = []
  c = 1
  a.each do |x|
    b << lcm(c,x)
    c = x
  end
  b << c
  puts b.join(' ')
end
