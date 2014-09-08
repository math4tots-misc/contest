import Data.List (tails)
import Data.Char (digitToInt)

main :: IO()
main =
    let toInt = read :: String -> Int in
    getLine >>= \t_str -> let t = toInt t_str in
    mapM_ (\_ ->
        getLine >>= \nk_str -> let [n,k] = map toInt $ words nk_str in
        getLine >>= \ds_str -> let ds = map digitToInt ds_str in
        print $
            maximum [product xs |
                xs' <- tails ds,
                let xs = take k xs',
                length xs == k]) [1..t]

