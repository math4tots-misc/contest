# https://www.hackerrank.com/contests/101jun14/challenges/sherlock-and-gcd

gets.to_i.times do
  gets
  puts(gets.split.map(&:to_i).inject(0){|a,b| a.gcd(b)} == 1 ? "YES" : "NO")
end

# 0  0.05s : Success 
# 1  0.04s : Success 
# 2  0.05s : Success 
# 3  0.04s : Success 
# 4  0.04s : Success 
# 5  0.04s : Success 
# 6  0.04s : Success 
# 7  0.04s : Success 
# 8  0.04s : Success 
# 9  0.03s : Success 
# 10  0.04s : Success 
# 11  0.04s : Success 
# 12  0.04s : Success 
# 13  0.04s : Success 
# 14  0.04s : Success 
# 15  0.04s : Success 