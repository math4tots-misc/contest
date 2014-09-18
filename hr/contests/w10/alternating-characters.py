from itertools import groupby

for _ in range(int(input())):
    print(sum(len(tuple(c))-1 for _, c in groupby(input().strip())))
