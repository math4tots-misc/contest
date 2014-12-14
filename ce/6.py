from sys import argv

def memoize(f):
  memo = dict()
  def wrapper(*args):
    if args not in memo:
      memo[args] = f(*args)
    return memo[args]
  return wrapper

@memoize
def lcs(a, b):
  return (''                           if a == '' or b == '' else
          lcs(a[:-1], b[:-1]) + a[-1]  if a[-1] == b[-1]     else
          max(lcs(a[:-1], b), lcs(a, b[:-1]), key=len))

with open(argv[1], 'r') as f:
  for line in f:
    if not line.strip(): continue
    print(lcs(*line.split(';')))
