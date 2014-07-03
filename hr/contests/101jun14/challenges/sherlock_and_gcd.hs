-- https://www.hackerrank.com/contests/101jun14/challenges/sherlock-and-gcd

import Data.List
import Data.List.Split
import Control.Monad

solve :: [Int] -> String
solve (a:as) = if foldl' gcd a as == 1 then "YES" else "NO"

process_one :: IO()
process_one =
	getLine >>
	getLine >>=
		putStrLn . solve . (map (read :: String -> Int)) . (splitOn " ")

main :: IO()
main =
	getLine >>=
		(\t -> forM_ [1..t] (\_ -> process_one)) . read

-- # 0  0.03s : Success 
-- # 1  0.02s : Success 
-- # 2  0.03s : Success 
-- # 3  0.02s : Success 
-- # 4  0.02s : Success 
-- # 5  0.03s : Success 
-- # 6  0.04s : Success 
-- # 7  0.02s : Success 
-- # 8  0.02s : Success 
-- # 9  0.02s : Success 
-- # 10  0.02s : Success 
-- # 11  0.02s : Success 
-- # 12  0.02s : Success 
-- # 13  0.02s : Success 
-- # 14  0.02s : Success 
-- # 15  0.02s : Success 
