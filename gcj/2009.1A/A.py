N_LIMIT = 100000
B_LIMIT = 11
MEMO = [ None ] * B_LIMIT

def init():
	for b in range(2,11):
		h = [None] * N_LIMIT
		h[1] = True
		for n in range(2,b ** 3):
			h[n] = calculate_happiness(n,b)
		
		for n in range(b,N_LIMIT):
			h[n] = h[sum_of_square_digits(n,b)]
		
		MEMO[b] = h

def sum_of_square_digits(n,b):
	m = 0
	while n:
		m += (n % b) ** 2
		n //= b
	return m

def calculate_happiness(n,b):
	s = set()
	while n != 1 and n not in s:
		s.add(n)
		n = sum_of_square_digits(n,b)
	return n == 1

def faster_calculate_happiness(n,b):
	while n >= N_LIMIT:
		n = sum_of_square_digits(n,b)
	return MEMO[b][n]

# for n in range(1000):
# 	print("%-4s: %s"% (n,calculate_happiness(n,10)))

print([n for n in range(1000) if calculate_happiness(n,10)])
