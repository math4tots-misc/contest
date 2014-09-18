import qualified Data.Sequence as Seq
import Data.Sequence (Seq)

type Matrix = Seq (Seq Int)

get :: Matrix -> Int -> Int -> Int
get m r c = Seq.index (Seq.index m r) c

multiply :: Matrix -> Matrix -> Matrix
multiply a b =
    let
    a_r = Seq.length a
    b_r = Seq.length b
    b_c = Seq.length $ Seq.index b 0
    in
    Seq.fromList [
    Seq.fromList [sum [
        rem (get a r k * get b k c) 1000000007
        | k <- [0..(b_r-1)]]
        | c <- [0..(b_c-1)]]
        | r <- [0..(a_r-1)]]

identity :: Int -> Matrix
identity n =
    Seq.fromList [
    Seq.fromList [if r == c then 1 else 0
        | c <- [0..(n-1)]]
        | r <- [0..(n-1)]]

exponentiate :: Matrix -> Int -> Matrix
exponentiate a 0 = identity $ Seq.length a
exponentiate a n =
    let
    b = exponentiate (multiply a a) (n `quot` 2)
    in
    if n `rem` 2 == 1
        then multiply a b
        else b

dynamicProgramming :: [Int] -> Int -> Seq Int
dynamicProgramming hs n =
    let
    ss :: Seq Int
    ss = 1 : Seq.fromList [
            sum [Seq.index ss (i - h)
                | h <- hs]
        | i <- [1..n]]
    in ss

transformationMatrix :: [Int] -> Int -> Matrix
transformationMatrix hs n =
    let
    
    in