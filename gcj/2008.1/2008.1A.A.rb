# 2008 Round 1A Problem A

# Solution follows trivially from rearrangement inequality

(1..gets.to_i).each do |t|
	n = gets.to_i
	v1 = gets.split.map(&:to_i).sort
	v2 = gets.split.map(&:to_i).sort.reverse
	m = v1.zip(v2).inject(0) {|sum,(a,b)| sum+a*b}
	puts "Case ##{t}: #{m}"
end
