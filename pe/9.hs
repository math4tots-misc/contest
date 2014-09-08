main :: IO ()
main =
    let toInt = read :: String -> Int in
    getLine >>= \t_str-> let t = toInt t_str in
    mapM_ (\_->
        getLine >>= \n_str-> let n = toInt n_str in
        let
        abcs =
            [ a * b * c |
                a <- [1..n],
                b <- [(a+1)..(quot (n-a) 2)],
                let c = n - a - b,
                a^2 + b^2 == c^2 ]
        in print (
            if null abcs
                then -1
                else maximum abcs)) [1..t]
