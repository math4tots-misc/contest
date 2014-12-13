# This solution turned out to be a bad idea.
# It doesn't work because numbers that start with '0'
# are interpreted as octal in Python2, and is simply rejected
# in Python3.
# -------------
# Oh wait, simple fix. Just use regex to get rid of those pesky
# leading zeros. It works in both python2 and 3!
from sys import argv
from itertools import product
from re import sub
ops = ('', '+', '-')
ugly = lambda i : any(i%p==0 for p in (2, 3, 5, 7))
mix = lambda n, opl: ''.join(d+op for d, op in zip(n, opl + ('',)))
exprs = lambda n : [mix(n, opl) for opl in product(ops, repeat=len(n)-1)]
sanitize = lambda expr: sub(r'\b0*', '', expr)
solve = lambda n : sum(ugly(eval(sanitize(expr))) for expr in exprs(n))

# with open(argv[1], 'r') as f:
#   for line in f:
#     if not line.strip(): continue
#     print(solve(line.strip()))
solve('1' * 13)
