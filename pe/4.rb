require 'set'

s = Set.new

(100..999).each do |i|
	(100..999).each do |j|
		k = i * j
		s << k if k.to_s.reverse.to_i == k
	end
end

s = s.to_a.sort!

gets.to_i.times do
	n = gets.to_i
	a = 0
	b = s.size
	while a+1 < b
		c = (a+b)/2
		if s[c] < n
			a = c
		else
			b = c
		end
	end
	puts s[a]
end


