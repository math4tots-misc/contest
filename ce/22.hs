import System.Environment

-- classic memoized fibonacci in haskell
fib = (map fib' [0..] !!) where
  fib' 0 = 0
  fib' 1 = 1
  fib' n = fib (n-2) + fib (n-1)

main = do
  args <- getArgs
  text <- readFile $ head args
  mapM_ print $ map (fib . read) $ lines text
