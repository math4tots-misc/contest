"""
Disk with radius 1 -> 1 millilitre of paint
Disk with radius r -> r^2 paint

(i indexed from 0, and only considering black rings)
Ring i -> (disk r+1+2*i) - (disk r+2*i) = (1) * (2*r+4*i+1)

(0...n excludes n)
Rings 0...n -> (disk r+1) + (disk r+3) + ... - (disk r) - (disk r+2)...
     -> (r+1)^2 + (r+3)^2 ... + (r+1+2*(n-1))^2
         - r^2 - (r+2)^2 ... + (r+2*(n-1))^2
         
    = sum (i = 0 to n-1) (2 * r + 4 * i + 1)
    = 2 * n * r + 4*n*(n-1)/2 + n
    = n*(2*r + 4*(n+1)/2 + 1)
"""

def needed(n):
	"amount of paint needed to draw n rings"
	return 2*n*r + 4*n*(n-1) // 2 + n

for test in range(1,int(input())+1):
	r, t = map(int,input().split())
	
	a = 0
	b = t
	
	while a+1 < b:
		c = (a+b)//2
		if needed(c) <= t:
			a = c
		else:
			b = c
	
	print('Case #%s: %s' % (test, a))

