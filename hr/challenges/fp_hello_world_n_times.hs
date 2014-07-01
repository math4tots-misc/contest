-- https://www.hackerrank.com/challenges/fp-hello-world-n-times

main = do
	n <- readLn :: IO Int
	putStr $ concat $ replicate n "Hello World\n"

