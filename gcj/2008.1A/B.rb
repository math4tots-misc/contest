# First assume none of them are malted.
# Then iterate over remaining preferences, and if any of them must have malted,
# then, malt that flavor.

# Since it is guaranteed that the number of preference pairs in a test case
# will not exceed 3000, running time is O(M * 3000)

require 'set'

(1..gets.to_i).each do |c|
	n = gets.to_i
	m = gets.to_i
	
	# must[0] is the set of all falvors that must be ummalted,
	# must[1] is the set of all flavors that must be malted.
	must = [Set.new, Set.new]
	
	preferences = m.times.collect do
		t, *rest = gets.split.map(&:to_i)
		rest.each_slice(2).collect { |(x,y)| [x-1,y] }
	end
	
	# As long as there is a preference of size 1, we may make a deduction.
	while preferences.any? { |preference| [0,1].include? preference.size }
		
		# Concede to people who demand exactly one kind of drink.
		preferences.each do |preference|
			if preference.size == 1
				x, y = preference[0]
				must[y] << x
			end
		end
		
		# Update preferences based on this new information
		preferences.map! do |preference|
			if preference.size > 1 && !preference.any? {|(x,y)| must[y].include? x}
				preference.reject {|(x,y)| must[1-y].include? x}
			end
		end.reject!(&:nil?)
		
		# Now if any of the preferences are empty, we have hit an impossible
		# situation
		if preferences.include? []
			must[0] << -1
			must[1] << -1
			break
		end
		
	end
	
	answer = if (must[0]&must[1]).size > 0
		"IMPOSSIBLE"
	else
		n.times.collect {|i| must[1].include?(i) ? '1' : '0'} .join(' ')
	end
	
	puts "Case ##{c}: #{answer}"
end
