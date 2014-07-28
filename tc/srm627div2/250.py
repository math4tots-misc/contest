class ManySquares:
	def howManySquares(self,sticks):
		counter = [0 for _ in range(1001)]
		for stick in sticks:
			counter[stick] += 1
		return sum(count // 4 for count in counter)
