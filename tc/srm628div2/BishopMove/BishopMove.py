# Actually later realized all reachable positions may be reached in at most 2 moves.
# Meh. This solution is still simple enough, and the board is so small that
# speed really isn't an issue.
from collections import deque

class BishopMove:
	def howManyMoves(self,r1,c1,r2,c2):
		return self.flood_fill(r2,c2)[r1,c1]
	
	def flood_fill(self,r,c):
		board = {(r,c):-1 for r in range(8) for c in range(8)}
		queue = deque([(r,c,0)])
		while queue:
			r, c, n = queue.popleft()
			if r in range(8) and c in range(8) and board[r,c] == -1:
				board[r,c] = n
				for dr, dc in ((1,1),(-1,-1),(1,-1),(-1,1)):
					for m in range(1,8):
						queue.append((r+m*dr,c+m*dc,n+1))
		return board
	
