MOD = 10 ** 9 + 7

def multiply(A,B):
    R = len(A)
    K = len(B)
    C = len(B[0])
    return [[sum(A[r][k] * B[k][c]
        for k in range(K)) % MOD
        for c in range(C)]
        for r in range(R)]

def identity(D):
    return [[1 if r == c else 0
        for c in range(D)]
        for r in range(D)]

def exponentiate(A,n):
    B = A
    C = identity(len(A))
    while n:
        if n%2:
            C = multiply(C,B)
        B = multiply(B,B)
        n //= 2
    return C

N = int(input())
int(input())
H = tuple(map(int,input().split()))

R = C = 15

M = [[0 for c in range(C)] for r in range(R)]

# If it's any column 0 .. (C-1),
# we just want the value of the next column
for c in range(C-1):
    M[c+1][c] = 1

# For the last column, use the available heights
# to fill them in.
for h in H:
    M[-h][-1] = 1

DP = [1 if i == 0 else 0 for i in range(R)]

for i in range(1,len(DP)):
    for h in H:
        if h <= i:
            DP[i] += DP[i-h]

print(
    (2*multiply([DP],exponentiate(M, N))[0][0]) %
    MOD)

