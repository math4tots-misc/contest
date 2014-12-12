from sys import argv

with open(argv[1], 'r') as f:
  for line in f.read().splitlines():
    if not line.strip():
      break
    X, Y, N = map(int, line.split())
    print(' '.join(
      'FB'   if n % X == n % Y == 0 else
      'F'    if n % X == 0          else
      'B'    if n % Y == 0          else
      str(n)
      for n in range(1,N+1)))

