# still getting time out... (gneck.old.py)
# Less abstraction this time. Hopefully runs fast enough.

# Yay! This one passes all the tests.

def solveall():
	MOD = 10 ** 9 + 7
	ZERO = [0                  for r in range(3) for c in range(3)]
	ONE  = [1 if r == c else 0 for r in range(3) for c in range(3)]
	MEMO = [
		[
			0, 0, 1,
			1, 0, 0,
			0, 1, 1
		]
	] + [None] * 60
	
	def mul(A,B):
		C = list(ZERO)
		for r in range(3):
			for c in range(3):
				for k in range(3):
					C[3*r+c] += A[3*r+k] * B[3*k+c]
					C[3*r+c] %= MOD
		return C
	
	for i in range(60):
		MEMO[i+1] = mul(MEMO[i], MEMO[i])
	
	def exp(n):
		A = ONE
		for i in range(60):
			if n % 2 == 1:
				A = mul(A,MEMO[i])
			n //= 2
		return A
	
	for _ in range(int(input())):
		X = exp(int(input()))
		print((X[0] + 2*X[3] + 3*X[6]) % MOD)

solveall()
