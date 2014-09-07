def solve(N,K,X,P):
  # Game types
  #  0 -> player 2 wins
  #  1 -> player 1 wins
  
  ############
  #### len(P) ~ 20K iterations
  lim_x = max(x for x, y in P) + 1
  lim_y = max(y for x, y in P) + 1
  
  # Calculate single_game_memo.
  # Determines winners of single knight games as a function of 
  # of a position on the board.
  
  from itertools import combinations_with_replacement
  
  ############
  #### 2 ** X ~ 32 iterations
  diffs = set(
    (sum(dx for dx, _ in ds), sum(dy for _, dy in ds))
    for ds in combinations_with_replacement( ((1,2),(2,1)), X))
  
  
  ############
  #### 300 * 300  ~ 90K iterations
  single_game_memo = [ None ] * (lim_x * lim_y)
  
  ############
  #### 300 * 300 * (2 ** X) ~ 3mil iterations
  for x in range(lim_x):
    for y in range(lim_y):
      single_game_memo[lim_y * x + y] = 0 if all(
        x - dx < 0 or
        y - dy < 0 or
        single_game_memo[lim_y * (x-dx) + (y-dy)] == 1
        for dx, dy in diffs) else 1
  
  # Calculate multi_game_memo.
  # Determines winners of the overall game depending on the number of
  # '1' game types on the board.
  
  ############
  #### len(P) ~ 20K iterations
  lim_n = sum(single_game_memo[lim_y * x + y] for x, y in P) + 1
  
  multi_game_memo = [ None ] * lim_n
  
  # ############
  # #### len(P) * K ~ 400mil iterations
  # # Ah ha ...
  # # How did I miss this the first time ...
  # # Well We can just calculate this in a smarter way
  # for n in range(lim_n):
  #   multi_game_memo[n] = 1 if any(
  #     n - dn >= 0 and
  #     multi_game_memo[n - dn] == 0
  #     for dn in range(1,K+1)) else 0
  
  count = 0
  for i in range(lim_n):
    if i - K - 1 >= 0 and multi_game_memo[i-K-1] == 0:
      count -= 1
    
    multi_game_memo[i] = 1 if count > 0 else 0
    
    if multi_game_memo[i] == 0:
      count += 1
  
  # Now with all this precalculations out of the way,
  # We may get the answer by looking up the answer in the table we just created
  return multi_game_memo[-1]

for _ in range(int(input())):
  N, K, X = map(int,input().split())
  P = tuple(tuple(map(int,input().split())) for _ in range(N))
  print('First player wins' if solve(N,K,X,P) else 'Second player wins')

