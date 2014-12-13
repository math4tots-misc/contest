from sys import argv
with open(argv[1], 'r') as f: s = f.read()

N, *lines = s.splitlines()
N = int(N)
lines = sorted(lines, reverse=True, key=lambda line: len(line))

for line in lines[:N]:
  print(line)
