class Tree(object):
	def __init__(self,weight,feature=None,subtrees=None):
		self.weight = weight
		self.feature = feature
		self.subtrees = subtrees
	
	def test(self,animal):
		if self.feature == None:
			return self.weight
		
		return self.weight * (self.subtrees[0 if self.feature in animal.features else 1].test(animal))
	
class Animal(object):
	def __init__(self,features):
		self.features = features

import re

re_space = re.compile(r'\s*')
re_token = re.compile(r'\(|\)|(?:\d+\.?\d*)|\w+')

def tokenize(s):
	tokens = []
	i = re_space.match(s).end()
	while i < len(s):
		match = re_token.match(s,i)
		tokens.append(match.group())
		if tokens[-1][0].isdigit():
			tokens[-1] = float(tokens[-1])
		i = match.end()
		i = re_space.match(s,i).end()
	return tokens

def parse_tree(tokens,i):
	i[0] += 1 # tokens[i] == '('
	weight = tokens[i[0]]
	i[0] += 1
	if tokens[i[0]] != ')':
		feature = tokens[i[0]]
		i[0] += 1
		subtree1 = parse_tree(tokens,i)
		subtree2 = parse_tree(tokens,i)
		i[0] += 1 # tokens[i] == ')'
		return Tree(weight,feature,[subtree1,subtree2])
	i[0] += 1 # tokens[i] == ')'
	return Tree(weight)

def read_tree():
	L = int(input())
	return parse_tree(tokenize(''.join(input() for _ in range(L))), [0])

def read_animal():
	name, n, *features = input().split()
	return Animal(frozenset(features))

def solve_case(i):
	print('Case #' + str(i) + ':')
	tree = read_tree()
	A = int(input())
	for _ in range(A):
		print(tree.test(read_animal()))

for i in range(1,1+int(input())):
	solve_case(i)


