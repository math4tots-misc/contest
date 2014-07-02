# https://www.hackerrank.com/challenges/connecting-towns

gets.to_i.times do
  gets
  puts(gets.split.map(&:to_i).inject(&:*)%1234567)
end

# 0  0.07s : Success 
# 1  0.05s : Success 
# 2  0.07s : Success 
# 3  0.05s : Success 
# 4  0.07s : Success 
# 5  0.07s : Success 
# 6  0.07s : Success 
# 7  0.07s : Success 
# 8  0.07s : Success 
# 9  0.05s : Success 

# Interesting ... I thought this should be slower than the
# haskell version, because the ruby version deals with big
# integers and only takes modulo at the end. But it looks like
# the ruby version has won out here.