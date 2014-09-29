merge :: String -> String -> String
merge [] [] = []
merge (ph:p) (qh:q) = ph:qh:(merge p q)

main =
    getLine >>= \ p ->
        getLine >>= \ q ->
            putStrLn (merge p q)

