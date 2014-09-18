N, K = map(int,input().split())
S = tuple(map(int,input().strip()))
message = []
accum = 0
for _, s in zip(range(N),S):
    message.append(accum ^ s)
    accum ^= message[-1]
    if len(message) >= K:
        accum ^= message[-K]

print(''.join(map(str,message)))

