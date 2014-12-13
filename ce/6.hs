-- Unfortunately memoizing in Haskell can get tricky...
-- This version will run too slowly.
lcs :: String -> String -> String
lcs a [] = []
lcs [] b = []
lcs a@(ha:ta) b@(hb:tb) =
  if ha == hb then ha : lcs ta tb
  else
    let lcsa = lcs a tb
        lcsb = lcs ta b
    in if length lcsa > length lcsb then lcsa else lcsb

main = print $ lcs ['a' | _ <- [1..50]] ['b' | _ <- [1..50]]
