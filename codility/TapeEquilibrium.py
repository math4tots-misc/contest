# you can use print for debugging purposes, e.g.
# print "this is a debug message"

def solution(A):
    # write your code in Python 2.7
    
    # If N == 1, there is no valid choice of P.
    # So it does not seem as though there is a well defined
    # value to return in that case.
    
    N = len(A)
    first = A[0]
    second = sum(A[1:])
    best = abs(first - second)
    P = 2
    while P < N:
        first += A[P-1]
        second -= A[P-1]
        best = min(best, abs(first - second))
        P += 1
    return best
    
