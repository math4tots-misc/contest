def solve(s):
	memo = {'':True}
	pairs = ('()','[]','{}')
	def special(s):
		if s not in memo:
			memo[s] = (
				False if any(s.count(p[0]) != s.count(p[1]) for p in pairs) else
				any(special(s[:i]) and special(s[i:]) for i in range(2,len(s)-1)) or
				((s[0]+s[-1]) in pairs and special(s[1:-1])))
		return memo[s]
	return any(solve(s.replace('X',c,1)) for c in '()[]{}') if 'X' in s else special(s)

class BracketExpressions:
	def ifPossible(self,s):
		return 'possible' if solve(s) else 'impossible'
