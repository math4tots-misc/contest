# 2008 Qualifier Problem B

class String
	# assuming this is a String of the fomr "HH:MM"
	# convert it into number of minutes since "00:00"
	def to_minutes
		h, m = split(':').map(&:to_i)
		60 * h + m
	end
end

READY = 0
DEPART = 1
A = 0
B = 1

(1..gets.to_i).each do |n|
	t = gets.to_i
	na, nb = gets.split.map(&:to_i)
	events = []
	na.times do
		depart_time, arrive_time = gets.split.map(&:to_minutes)
		# at depart_time, a train will have to leave at A
		# at arrive_time+t, a train will be ready at B
		events << [depart_time, DEPART, A]
		events << [arrive_time + t, READY, B]
	end
	nb.times do
		depart_time, arrive_time = gets.split.map(&:to_minutes)
		events << [depart_time, DEPART, B]
		events << [arrive_time + t, READY, A]
	end
	
	# sort events by time, and given ties, choose READY events before
	# DEPART (if a train becomes available at 10:00 and a train needs to
	# leave at 10:00, you can use that same train for departure)
	events.sort!
	
	start = [0, 0] # trains at A and B at the start of the day
	at    = [0, 0] # trains at A and B
	
	for time, type, station in events
		case type
		when READY
			at[station] += 1
		when DEPART
			if at[station] > 0
				at[station] -= 1
			else
				start[station] += 1
			end
		end
	end
	
	puts "Case ##{n}: #{start.map(&:to_s).join' '}"
end
