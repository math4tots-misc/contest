'''
Created on Jul 28, 2014

@author: math4tots
'''

class NegativeGraphDiv2:
    def findMin(self,N,S,T,W,C):
        from heapq import heapify, heappop, heappush
        def solve(N,S,T,W,C):
            neighbors_from = [[] for _ in range(N+1)]
            neighbors_to = [[] for _ in range(N+1)]
            smallest_edge = [[None for _ in range(N+1)] for _ in range(N+1)]
            largest_edge = [[None for _ in range(N+1)] for _ in range(N+1)]
            for s, t, w in zip(S,T,W):
                if t not in neighbors_from[s]:
                    neighbors_from[s].append(t)
                    neighbors_to[t].append(s)
                    smallest_edge[s][t] = largest_edge[s][t] = w
                else:
                    smallest_edge[s][t] = min(smallest_edge[s][t],w)
                    largest_edge[s][t] = max(largest_edge[s][t],w)
            memo = [ [float('inf') for _ in range(1001)] for _ in range(51)]
            estimate = [ [float('inf') for _ in range(1001)] for _ in range(51)]
            queue = [ (0,N) ]
            queue2 = {}
            charge = 0
            while queue or queue2:
                if not queue:
                    queue = [(cost,node) for (node,cost) in queue2.items()]
                    heapify(queue)
                    queue2 = {}
                    charge += 1
                    if charge > C:
                        break
                cost, node = heappop(queue)
                if estimate[node][charge] < cost or memo[node][charge] <= cost:
                    continue
                memo[node][charge] = estimate[node][charge] = cost
                for neighbor in neighbors_to[node]:
                    new_cost = cost+smallest_edge[neighbor][node]
                    if new_cost < estimate[neighbor][charge]:
                        estimate[neighbor][charge] = new_cost
                        heappush(queue, (new_cost,neighbor))
                    queue2[neighbor] = min(queue2.get(neighbor,float('inf')),cost-largest_edge[neighbor][node])
            return min(memo[1])
        return solve(N,S,T,W,C)
  
N = 2
S = [1]
T = [2]
W = [98765]
C = 100
g = NegativeGraphDiv2()
print(g.findMin(N, S, T, W, C))
