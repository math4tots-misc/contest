#https://www.codeeval.com/open_challenges/156/
# First solution assumed entire chunk was one test case.
# Realized each line was its own test case.

def solve(line):
	chars = list(line)
	new_chars = []
	upper = True
	for c in chars:
		if c.isalpha():
			if upper:
				new_chars.append(c.upper())
			else:
				new_chars.append(c.lower())
			upper ^= True
		else:
			new_chars.append(c)
	return ''.join(new_chars)

from sys import argv

answers = []
with open(argv[1],'r') as f:
	for line in f:
		answers.append(solve(line))
print(''.join(answers))
