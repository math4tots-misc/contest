# def solve(E,R,N,V):
#     """O(N^2) solution"""
#     A = [ 0 ] * N # must have at least A[i] energy after  activity i
#     B = [ E ] * N # have left at most  B[i] energy before activity i
#     t = 0
    
#     for i in sorted(range(N), key=lambda i : -V[i]):
#         t += V[i] * (B[i] - A[i])
        
#         j = i+1
#         while j < N and A[i] + R * (j-i) < B[j]:
#             B[j] = A[i] + R * (j-i)
#             j += 1
        
#         j = i-1
#         while j >= 0 and B[i] - R * (i-j) > A[j]:
#             A[j] = B[i] - R * (i-j)
#             j -= 1
        
#     return t

def solve(E,R,N,V):
    """O(N) solution -- as described in official solutions"""
    
    # n[i] will be index to next position with higher value
    n = [ None ] * N 
    stack = [ ]
    for i, v in reversed(tuple(enumerate(V))):
        while stack and V[stack[-1]] < v:
            stack.pop()
        if stack:
            n[i] = stack[-1]
        stack.append(i)
    del stack
    
    # Now that 'n' is built, we may iterate over V and figure out
    # how much energy to spend for each activity.
    total = 0
    energy = E
    for i, v in enumerate(V):
        
        if n[i] is None:
            # If there is no activity with higher priority, spend all
            # available energy
            spend = energy
        else:
            # Otherwise, save as much as possible for next higher priority
            # activity without being wasteful.
            # 
            # We will have
            #   energy + (n[i]-i) * R - spend
            # left when we reach n[i].
            # So we should not spend more than
            #   energy + (n[i]-i) * R - E
            # 
            # We also can't spend negative energy
            spend = max(0, min(energy, energy + (n[i]-i)*R - E))
        
        energy -= spend
        energy += R
        energy = min(energy, E)
        total += v * spend
    
    return total

for test in range(1,int(input())+1):
    E, R, N = map(int,input().split())
    V = tuple(map(int,input().split()))
    print("Case #%s: %s" % (test,solve(E,R,N,V)))
