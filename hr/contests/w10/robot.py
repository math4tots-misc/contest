N = int(input())
V, P = zip(*[map(int,input().split()) for _ in range(N)])

memo = [ None ] * N
memo[0] = 0

for i in range(1,len(memo)):
    memo[i] = max(memo[i-1]-1+V[i-1], P[i-1])

print(memo[-1] + V[-1] - 1)
