-- Too slow ... won't pass last test case

import Control.Monad.ST
import Control.Monad
import Data.STRef
import Data.Array.ST

max_n :: Int
max_n = 1000000

sieve :: UArray Int Bool
sieve = runSTUArray $
    newArray (2, max_n) True >>= \sieve ->
    forM_ [2 .. max_n] (\p ->
        readArray sieve p >>= \isPrime ->
        when isPrime
            (forM_ [p*2, p*3 .. max_n] (\k ->
                writeArray sieve k False))) >>
    return sieve

primes :: [Int]
primes = [i | (i,isPrime) <- assocs sieve, isPrime]

main :: IO ()
main =
    let toInt = read :: String -> Int in
    getLine >>= \t_str -> let t = toInt t_str in
    forM_ [1 .. t] (\_ ->
        getLine >>= \n_str -> let n = toInt n_str in
        print $ sum $ takeWhile (<= n) primes)

