# Contest is over....

# Read solution and realized I had seen this before.
# Problem involves encoding the recursion in a matrix,
# and exponentiating. Exponentiating can be done in log(n)
# by calculating matrices of powers of two, and then
# multiplying the appropriate ones

# The recurrence relation is f(n) = f(n-1) + f(n-3)
# with f(0) = 1, f(1) = 2, f(2) = 3
# The recurrence matrix is
"""
[
	[0, 0, 1],
	[1, 0, 0],
	[0, 1, 1]
]
"""
# Starting vector is
"""
[1, 2, 3]
"""

M = 10 ** 9 + 7

class Matrix(object):
	def __init__(self, data = None):
		if data is None:
			data = [[0 for _ in range(3)] for _ in range(3)]
		self.data = data
	
	def __getitem__(self,pos):
		row, col = pos
		return self.data[row][col]
	
	def __setitem__(self,pos,val):
		row, col = pos
		self.data[row][col] = val
	
	def __add__(A,B):
		return Matrix([[(A[r,c]+B[r,c])%M for c in range(3)] for r in range(3)])
	
	def __mul__(A,B):
		m = Matrix()
		for r in range(3):
			for c in range(3):
				for k in range(3):
					m[r,c] += A[r,k] * B[k,c]
					m[r,c] %= M
		return m
	
	# def __pow__(A,n):
	# 	"This recursive version is too slow"
	# 	if n == 0:
	# 		return Matrix([[1 if r==c else 0 for c in range(3)] for r in range(3)])
	# 	elif n == 1:
	# 		return A
		
	# 	if n in A.
		
	# 	m = A ** (n//2)
	# 	m *= m
	# 	if n%2 == 1:
	# 		m *= A
		
	# 	return m
	
	def __pow__(A,n):
		"Does not work in general"
		B = Matrix([[1 if r==c else 0 for c in range(3)] for r in range(3)])
		i = 0
		while n > 0:
			if n%2 == 1:
				B *= memo[i]
			i += 1
			n //= 2
		return B
	
	def __eq__(A,B):
		return A.data == B.data
	
	def __ne__(A,B):
		return not (A == B)
	
	def __repr__(self):
		return repr(self.data)

s = Matrix([[1,2,3] for _ in range(3)])

m = Matrix([
	[0, 0, 1],
	[1, 0, 0],
	[0, 1, 1]
])

memo = [ m ]
for _ in range(70):
	memo.append(memo[-1] * memo[-1])

for _ in range(int(input())):
	print((s * m ** int(input()))[0,0])

