import Data.Set

remove_duplicates :: String -> String
remove_duplicates s =
	reverse (f s [] empty)
	where
		f :: String -> String -> Set Char -> String
		f (c:s) os h
			| member c h = f s    os         h
			| otherwise  = f s (c:os) (union h $ singleton c)
		f [] os h = os

main :: IO()
main = getContents >>= (putStr . remove_duplicates)
