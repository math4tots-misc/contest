import Data.Bits (xor)

main =
    let toInt = read :: String -> Int in
    getLine >>= \nk_str -> let [n,k] = map toInt $ words nk_str in
    getLine >>= \s_str ->
    let ss = [if c == '1' then 1 else 0 | c <- s_str, c == '0' || c == '1'] in
    let
    
    bs :: [Int]
    bs = [a `xor` s | (a,s) <- zip as ss]
    
    as :: [Int]
    as = 0 : [a `xor` b `xor` db | (a,b,db) <- zip3 as bs $ (take (k-1) $ repeat 0) ++ bs]
    
    in putStrLn [if b == 1 then '1' else '0' | b <- take n bs]


    