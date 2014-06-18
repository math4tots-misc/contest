class Solver
	def solve
		n, @x = gets.split.map(&:to_i)
		@s = gets.split.map(&:to_i).sort!
		
		a = 0
		b = n
		while b-a > 1
			c = (a+b)/2
			if check c
				a = c
			else
				b = c
			end
		end
		
		return n - a
	end
	
	def check a
		return false if 2 * a > @s.size
		a.times do |i|
			return false if @s[i]+@s[2*a-1-i] > @x
		end
		return true
	end	
end

solver = Solver.new
(1..gets.to_i).each do |t|
	puts "Case ##{t}: #{solver.solve}"
end
