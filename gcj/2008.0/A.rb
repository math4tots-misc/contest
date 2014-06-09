# 2008 Qualification Round Problem A

require 'set'

(1..gets.to_i).each do |n|
	s = gets.to_i
	engines = s.times.collect { gets.strip }
	q = gets.to_i
	queries = q.times.collect { gets.strip }
	
	encountered = Set.new
	switches = 0
	
	for query in queries
		encountered.add query
		
		if encountered.size == s
			switches += 1
			encountered = Set.new [query]
		end
	end
	
	puts "Case ##{n}: #{switches}"
end

