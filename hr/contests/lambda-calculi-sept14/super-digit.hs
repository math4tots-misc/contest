-- Had to struggle a little bit to work out performance issues.

import qualified Data.Char as Char

digit_sum :: Int -> Int
digit_sum n =
    digit_sum' n 0
    where
        digit_sum' 0 t = t
        digit_sum' n t = digit_sum' (n `quot` 10) (t + (n `rem` 10))

string_digit_sum :: String -> Int
string_digit_sum = sum . map Char.digitToInt

super_digit :: Int -> Int
super_digit n
    | n < 10    = n
    | otherwise = super_digit $ digit_sum n

solve :: String -> Int -> Int
solve n k = super_digit (k * string_digit_sum n)

main =
    getLine >>= \ line ->
        let n:k:[] = words line
        in putStrLn $ show $ solve n (read k :: Int)

