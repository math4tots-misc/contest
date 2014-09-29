-- I wish memoization were easier in Haskell ....

cost :: Int -> Int -> [Int] -> Int
cost left right [] = 0
cost left right (digit:digits) = 1 + min
    ((abs (left  - digit)) + cost digit right digits)
    ((abs (right - digit)) + cost left  digit digits)

total_cost :: [Int] -> Int
total_cost digits = minimum [cost left right digits | left <- [1..10], right <- [1..10]]

main =
    getLine >>
    getLine >>= \ line ->
        putStrLn $ show $ total_cost [
            if digit == 0
                then 10
                else digit
            | digit <- [(read digit :: Int) | digit <- words line]]
