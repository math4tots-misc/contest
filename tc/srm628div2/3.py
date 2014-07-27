def solve(f):
	from functools import reduce
	def find_cycle(i,seen=frozenset(),cycle=frozenset()):
		return (
			cycle if i in cycle else 
			find_cycle(f[i],seen,cycle|frozenset([i])) if i in seen else 
			find_cycle(f[i],seen|frozenset([i]),cycle))
	def find_tree_product(i,excluding=frozenset()):
		product = 1
		for j in g[i]:
			if j not in excluding:
				product *= find_tree_product(j,excluding)
		return product + 1
	def mark_subtree_as_seen(i):
		if i not in seen:
			seen.add(i)
			for j in g[i]:
				mark_subtree_as_seen(j)
	
	n = len(f)
	g = [list() for i in range(n)]
	for i, j in enumerate(f):
		g[j].append(i)
	
	seen = set()
	answer = 1
	while len(seen) < n:
		for i in range(n):
			if i not in seen:
				cycle = find_cycle(i)
				gen1 = frozenset(x for c in cycle for x in g[c] if x not in cycle)
				answer *= reduce((lambda a,b : a * b), map(find_tree_product,gen1), 1) + 1
				seen |= cycle
				for c in gen1:
					mark_subtree_as_seen(c)
	return answer

class InvariantSets:
	def countSets(self,f):
		return solve(f)



