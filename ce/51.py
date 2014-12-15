from sys import argv
from math import sqrt
with open(argv[1], 'r') as f:
  while True:
    N = int(f.readline())
    if N == 0: break
    pts = [tuple(map(int,f.readline().split())) for _ in range(N)]
    dist = lambda a, b: sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)
    odist = lambda pt: dist((0,0), pt)
    pts.sort(key=odist)
    best = 10000
    for ia in range(len(pts)):
      a = pts[ia]
      for ib in range(ia+1, len(pts)):
        b = pts[ib]
        if odist(b) - odist(a) > best:
          break
        best = min(best, dist(a,b))
    print('INFINITY' if best == 10000 else ('%.4f' % best))
