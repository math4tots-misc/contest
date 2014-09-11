import Control.Monad

main =
    let
    solve :: [Int] -> Bool
    solve [] = True
    solve (x:xs) =
        any (\i->
            let (l,r) = splitAt i xs in
            all (< x) l &&
            all (> x) r &&
            solve l &&
            solve r) [0..length xs]
    in
    (readLn :: IO Int) >>= \t ->
    forM_ [1..t] (\_ ->
    (readLn :: IO Int) >>= \n ->
    getLine >>= \line ->
    let xs = map read $ words line in
    putStrLn (if solve xs then "YES" else "NO"))
    
