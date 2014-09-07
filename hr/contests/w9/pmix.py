# Can handle large K,
# But too slow when N is large
def solve():
  encode_table = {
    'A' : 0,
    'B' : 3,
    'C' : 1,
    'D' : 2
  }
  
  decode_table = { v:k for k,v in encode_table.items() }
  
  N, K = map(int,input().split())
  S = tuple(encode_table[c] for c in input().strip())
  X = tuple(x & 1 for x in S)
  Y = tuple(y & 2 for y in S)
  
  def dd(t):
    from math import log, ceil
    dx = ceil(log(t) / log(2))
    dt = 1 << dx
    if dt > t:
      dt >>= 1
    return dt
  
  def solve1(X):
    MEMO = dict()
    
    def f(x,t):
      x %= N
      if (x,t) not in MEMO:
        if t == 0:
          MEMO[x,t] = X[x]
        else:
          dt = dd(t)
          MEMO[x,t] = f(x, t-dt) ^ f(x+dt, t-dt)
      
      return MEMO[x,t]
    
    return tuple(f(x,K) for x in range(N))
  
  Z = tuple(x^y for x, y in zip(solve1(X), solve1(Y)))
  
  print(''.join(decode_table[z] for z in Z))

solve()
