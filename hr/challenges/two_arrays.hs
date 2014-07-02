-- https://www.hackerrank.com/challenges/two-arrays

-- Problem
-- Given arrays of Ints 'a' and 'b' and 
-- an Int 'k', test if it is possible to rearrange the values
-- in 'a' and 'b' such that 'a[i] * b[i] >= k' for all 'i'

import Data.List (sort)
import Data.List.Split (chunksOf,splitOn)

-- The main algorithm of the problem was simple enough.
-- Just one line of formula, and another optional line of type annotation.

solve :: [Int] -> [Int] -> Int -> Bool
solve a b k = all (\(x,y) -> (x+y >= k)) $ zip (sort a) (reverse . sort $ b)

-- Huh.
-- Well I guess the io was a lot more work than I had expected...
-- Perhaps if I get more experienced with Haskell, this part might get smoother...

main :: IO ()
main = do
	contents <- getContents
	
	let t_line:problem_lines = lines contents
	let t = read t_line :: Int
	
	mapM_ putStrLn $
		take t $
		map (\t -> if t then "YES" else "NO") $
		[solve a b k | (a,b,k) <- map parse $ chunksOf 3 $ problem_lines]
	
	where
		parse :: [String] -> ([Int],[Int],Int)
		parse [nk,a,b] = (line2ints a, line2ints b, line2ints nk !! 1)
		
		line2ints :: String -> [Int]
		line2ints s = map read (splitOn " " s)


-- # 0  0.02s : Success 
-- # 1  0.02s : Success 
-- # 2  0.02s : Success 
-- # 3  0.02s : Success 
-- # 4  0.05s : Success 
-- # 5  0.05s : Success 
-- # 6  0.07s : Success 
-- # 7  0.1s : Success 
-- # 8  0.05s : Success 
-- # 9  0.02s : Success 


-- Changed Integer to Int

--# 0  0.03s : Success 
--# 1  0.02s : Success 
--# 2  0.02s : Success 
--# 3  0.02s : Success 
--# 4  0.04s : Success 
--# 5  0.04s : Success 
--# 6  0.07s : Success 
--# 7  0.09s : Success 
--# 8  0.05s : Success 
--# 9  0.02s : Success 
