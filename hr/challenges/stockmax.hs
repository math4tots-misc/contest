import Control.Monad
import Data.List.Split

solve :: [Int] -> Int
solve xs =
	solve' x 0 rxs
	where
		rxs = reverse xs
		x = head rxs
		solve' :: Int -> Int -> [Int] -> Int
		solve' high total [] = total
		solve' high total (x:xs)
			| x   >  high  = solve' x      total          xs
			| otherwise    = solve' high  (total+high-x)  xs

main :: IO()
main =
	getLine >>= (\t -> forM_ [1..t] process_problem). read
	where
		process_problem :: Int -> IO()
		process_problem _ =
			getLine >>
			getLine >>= putStrLn . show . solve . (map read) . (splitOn " ")

-- # 0  1.71s : Success 
-- # 1  1.42s : Success 
-- # 2  0.96s : Success 
-- # 3  1.44s : Success 
-- # 4  1.53s : Success 
-- # 5  1.71s : Success 
-- # 6  1.33s : Success 
-- # 7  1.36s : Success 
-- # 8  1.61s : Success 
-- # 9  1.78s : Success 
-- # 10  0.02s : Success