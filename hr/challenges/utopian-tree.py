# python3

for _ in range(int(input())):
	N = int(input())
	height = 1
	for i in range(N):
		if i%2 == 0:
			height *= 2
		else:
			height += 1
	print(height)
