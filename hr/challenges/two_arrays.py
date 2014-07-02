# https://www.hackerrank.com/challenges/two-arrays

# Already did this one in C++ and Haskell.
# Wanted to compare performance

# Python 3.x

for _ in range(int(input())):
	N, K = map(int,input().split())
	A = list(map(int,input().split()))
	B = list(map(int,input().split()))
	A.sort()
	B.sort()
	B.reverse()
	print("YES" if all(a+b >= K for a,b in zip(A,B)) else "NO")

# So Python turned out kinda in the middle in terms of speed.
# It's possible most of it was just time it took to get
# Python's overhead working, as with Python all the runtime
# is the same, even when Haskell's runtime would somtimes get higher.

# 0  0.05s : Success 
# 1  0.05s : Success 
# 2  0.05s : Success 
# 3  0.05s : Success 
# 4  0.05s : Success 
# 5  0.05s : Success 
# 6  0.05s : Success 
# 7  0.05s : Success 
# 8  0.05s : Success 
# 9  0.05s : Success 

# Also it is a bit unfair for Haskell, as this Python solution spends very
# little time in Python, and methods like A.sort() spend a lot of time
# in the C-implementation.

# Perhaps in this line of reasoning,
# I got rid of the explicit loop over zip(A,B) and used a generator.
# I am not sure if this would speed anything up as the explicit test itself
# (a+b >= K) is in Python, and the construct to loop over (zip(A,B)) is
# an inherently Pythonic thing that might not be so natural in C.

# 0  0.05s : Success 
# 1  0.05s : Success 
# 2  0.05s : Success 
# 3  0.05s : Success 
# 4  0.05s : Success 
# 5  0.05s : Success 
# 6  0.05s : Success 
# 7  0.07s : Success 
# 8  0.05s : Success 
# 9  0.05s : Success 

# So in one case, this generator version is slower than the explicit loop
# 
# for a,b in zip(A,B):
# 	if a+b < K:
# 		print("YES")
# 		break
# else:
# 	print("NO")
#
# I might chuck it up to a statistical anomaly, but it also seems to be the
# testcase where haskell took the longest (0.09 and 0.1 seconds). So it
# could be the slower generator method showing.

# It is possible that if I had used a loop over the indices instead of a
# generator, it might have run faster. But I think I am beating a dead
# horse at this point.

# In terms of readability and code length, I think Python is the clear winner.
