-- https://www.hackerrank.com/challenges/connecting-towns

import Data.List.Split (chunksOf, splitOn)
import Data.List (foldl')

main = do
	cs <- getContents
	let (tl:ls) = lines cs
	let t = read tl :: Int
	let ps = chunksOf 2 ls
	mapM_ putStrLn $ map (show . (foldl' (\x y -> mod (x*y) 1234567) 1) . parse) ps
	where
		parse :: [String] -> [Int]
		parse [n,ni] = map read $ splitOn " " ni

--# 0  0.22s : Success 
--# 1  0.1s : Success 
--# 2  0.25s : Success 
--# 3  0.12s : Success 
--# 4  0.26s : Success 
--# 5  0.25s : Success 
--# 6  0.27s : Success 
--# 7  0.27s : Success 
--# 8  0.17s : Success 
--# 9  0.02s : Success