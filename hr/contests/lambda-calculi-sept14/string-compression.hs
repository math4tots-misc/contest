compress :: String -> String
compress [] = []
compress (c:[]) = c:[]
compress (c:c2:cs) =
    if c == c2
        then compress' c 2 cs
        else c:(compress (c2:cs))

compress' :: Char -> Int -> String -> String
compress' c n (c2:cs) =
    if c == c2
        then compress' c (n+1) cs
        else c : show n ++ compress (c2 : cs)

compress' c n [] = c : show n

main = getLine >>= putStrLn . compress

