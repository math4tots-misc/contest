from sys import argv
replacer = lambda old, new, f: (lambda s: new.join(map(f, s.split(old))))
with open(argv[1], 'r') as f:
  for line in f:
    line = line.strip()
    if not line: continue
    r = lambda x : x
    s, pairs = line.split(';')
    pairs = pairs.split(',')
    pairs = tuple(zip(pairs[0::2], pairs[1::2]))
    for old, new in reversed(pairs):
      r = replacer(old, new, r)
    print(r(s))
