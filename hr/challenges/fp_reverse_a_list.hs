-- https://www.hackerrank.com/challenges/fp-reverse-a-list

rev :: [a] -> [a]
rev l =
	rev' l []
	where
		rev' :: [a] -> [a] -> [a]
		rev' [] b = b
		rev' (x:xs) b = rev' xs (x:b)

-- The hackerrank submission system doesn't seem to care for custom io

--main :: IO ()
--main = do
--	l <- getContents
--	let rls = rev $ lines l
--	mapM_ putStrLn rls
--	
