gets.to_i.times do
  gets
  xs = gets.split.map(&:to_i).reverse!
  high = xs[0]
  total = 0
  xs.each do |x|
    if x >= high
      high = x
    else
      total += high - x
    end
  end
  puts total
end

# 0  0.18s : Success 
# 1  0.12s : Success 
# 2  0.09s : Success 
# 3  0.14s : Success 
# 4  0.14s : Success 
# 5  0.16s : Success 
# 6  0.12s : Success 
# 7  0.12s : Success 
# 8  0.14s : Success 
# 9  0.15s : Success 
# 10  0.04s : Success 