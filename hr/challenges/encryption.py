# https://www.hackerrank.com/challenges/encryption

from math import sqrt, floor, ceil
word = input().strip()
cols = ceil(sqrt(len(word)))
print(' '.join(word[i::cols] for i in range(cols)))

