import sys

with open(sys.argv[1]) as f:
  for line in f.read().strip().splitlines():
    nn = tuple(map(int, line.split()))
    d = {}
    for k, v in zip(nn[:-1], nn[1:]):
      if d.get(k, None) == v:
        x = k
        sys.stdout.write(str(x))
        x = d[x]
        while x != k:
          sys.stdout.write(" " + str(x))
          x = d[x]
        sys.stdout.write("\n")
        break
      d[k] = v
