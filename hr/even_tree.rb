# https://www.hackerrank.com/challenges/even-tree

############### Problem ############################
# Given a tree described by a list of edges,
# what is the maximum number of edges we can take
# away and get a forest of trees where each tree
# has an even number of nodes?
####################################################

############### Solution ############################
# We start from the leaves, and see what the smallest
# trees containing those leaves could possibly be.
# 
# The key heuristic we use is that when we have a
# connected subtree, and we know there is exactly
# one edge connecting that component to other
# components, we may determine whether we may keep
# or throw away that edge based on the parity of the
# number of nodes in that component.
####################################################

require 'set'

N, M = gets.split.map &:to_i

m = 0 # m is the number of edges we must use

P = Hash.new # P[i] is a Set of neighbors of i
S = Hash.new # S[i] is size of the connected subtree rooted at i
(1..N).each do |i|
	P[i] = Set.new
	S[i] = 1
end

M.times do
	a, b = gets.split.map &:to_i
	P[a].add b
	P[b].add a
end

changed = true
while changed
	changed = false
	
	(1..N).each do |i|
		if P[i].size == 1
			changed = true
			
			j = P[i].to_a[0]
			
			P[i].delete(j)
			P[j].delete(i)
			
			# We keep the edge between i and j iff S[i] is odd.
			# If the component rooted at 'i' has only one edge
			# to the oustide world, and it is odd, the only hope
			# for turning that odd component even is by extending it
			# using that last edge.
			if S[i].odd?
				S[j] += S[i]
				m += 1
			end

		end
	end
	
end

puts M-m
