import Data.List
import Control.Monad

main =
    let toInt = read :: String -> Int in
    getLine >>= \n_str -> let n = toInt n_str in
    forM_ [1..n] (\_ ->
        getLine >>= \s ->
        print $ sum (map ((\x -> x - 1) . length) $ group s))
