# Python 2.x

def solveall():
  def nCr(n,r):
    num = 1
    i = n-r+1
    while i <= n:
      num *= i
      i += 1
    
    den = 1
    i = 2
    while i <= r:
      den *= i
      i += 1
    
    return num // den
  
  def solve(N,M,K):
    letters = []
    
    while N > 0 and M > 0:
      split = nCr(M+N-1, M)
      
      if K < split:
        N -= 1
        letters.append('H')
      
      else:
        K -= split
        M -= 1
        letters.append('V')
    
    letters += [ 'H' ] * N
    letters += [ 'V' ] * M
    
    return ''.join(letters)
  
  for _ in range(int(raw_input())):
    N, M, K = map(int,raw_input().split())
    print(solve(N,M,K))

solveall()
