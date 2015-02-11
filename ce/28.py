import sys

with open(sys.argv[1]) as f:
  for line in f.read().splitlines():

    if ',' not in line:
      continue

    lh, rh = line.split(',')

    cache = {}

    def match(li, ri):
      if (li, ri) not in cache:
        cache[li, ri] = (
            True                                              if ri == len(rh)                              else
            any(match(i, ri+1) for i in range(li, len(lh)+1)) if rh[ri] == '*'                              else
            False                                             if li == len(lh)                              else
            match(li+1, ri+2)                                 if rh[ri] == '\\' and lh[li] == rh[ri+1:ri+2] else
            match(li+1, ri+1)                                 if lh[li] == rh[ri]                           else
            False)
      return cache[li, ri]

    print("true" if any(match(i, 0) for i in range(len(lh))) else "false")
