from fractions import Fraction
from math import factorial

cache = dict()

def nCr(n,r):
    return factorial(n) // factorial(r) // factorial(n-r)

def E(n, p):
  if (n, p) not in cache:
    cache[n, p] = (
        0 if n == 0 else
        (1/p) if n == 1 else
        (
            sum([1] + [nCr(n,i) * p ** (n-i) * (1-p) ** i * E(i, p) for i in range(n)]) /
            (1 - (1 - p) ** n)
        ))
  return cache[n, p]

def A(p):
  return float(E(20, Fraction(p)))

assert abs(A('0.1') - 34.64694) < 10 ** -5
assert abs(A('0.12') - 28.64398) < 10 ** -5
assert abs(A('0.123') - 27.91171) < 10 ** -5
assert abs(A('0.1234') - 27.81676) < 10 ** -5
assert abs(A('0.12345') - 27.80493) < 10 ** -5

for t in range(1, int(raw_input())+1):
  print "Case #%d: %f" % (t, A(raw_input()))
