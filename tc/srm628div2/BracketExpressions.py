memo = {'' : True}

pairs = ('()', '[]', '{}')

def special(s):
	if s not in memo:
		memo[s] = (
			any(special(s[:i]) and special(s[i:]) for i in range(1,len(s)-1)) or
			((s[0]+s[-1]) in pairs and special(s[1:-1])))
	return memo[s]

def solve(s):
	return any(solve(s.replace('X',c,1)) for c in '()[]{}') if 'X' in s else special(s)

class BracketExpressions:
	def ifPossible(self,s):
		return 'possible' if solve(s) else 'impossible'

