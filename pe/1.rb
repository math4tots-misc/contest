# huh... This one passes...
# I thought I tried the same thing with the scala version...
def f n
	(n*(n+1))/2
end

def g n
	f(n/3) * 3 + f(n/5) * 5 - f(n/15) * 15
end

gets.to_i.times do
	n = gets.to_i - 1
	puts g(n)
end
