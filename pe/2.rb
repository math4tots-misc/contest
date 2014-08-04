FMEMO = [ 0, 1 ]
SMEMO = [ 0, 0 ]

def find x
	while SMEMO[-1] < x
		FMEMO << FMEMO[-1] + FMEMO[-2]
		SMEMO << (SMEMO[-1] + (FMEMO[-1]%2 == 0 ? FMEMO[-1] : 0))
	end
	
	a = 0
	b = FMEMO.size
	
	while (a+1) < b
		i = (a+b)/2
		if FMEMO[i] < x
			a = i
		else
			b = i
		end
	end
	return SMEMO[a]
end

gets.to_i.times do
	puts(find gets.to_i)
end
