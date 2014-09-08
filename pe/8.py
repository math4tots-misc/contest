# Python solution works just fine
def product(xs):
    p = 1
    for x in xs:
        p *= x
    return p

for _ in range(int(input())):
    N, K = map(int,input().split())
    digits = [int(d) for d in input().strip()]
    print(max(product(digits[i:i+K]) for i in range(N - K + 1)))

