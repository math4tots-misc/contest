-- Yay!! passes all the tests!
-- Used essentially the same algorithm as the scala version
-- but this one runs within the time limit.
import Data.Set (Set)
import Data.Map (Map)
import Data.Sequence (Seq)
import qualified Data.Set as Set
import qualified Data.Map as Map
import qualified Data.Sequence as Seq

intstr :: String -> [Int]
intstr s = [(read x :: Int) | x <- words s]

indstr :: String -> [Int]
indstr s = [ x - 1 | x <- intstr s ]

main =
    getLine >>= \ nm_str ->
    let [n, m] = intstr nm_str in
    getLine >>= \ p_str ->
    let p = ((Map.fromList ((0, 0) : zip [1..(n-1)] (indstr p_str))) Map.!) in
    getContents >>= \ qs_str ->
    let qs = [indstr q | q <- lines qs_str] in
    let
        -- commonly used range
        r0n1 :: [Int]
        r0n1 = [1..(n-1)]
        
        -- ancestor set
        as :: Int -> Set Int
        as = ((Map.fromList (
            (0, Set.singleton 0) :
            [(i, Set.insert i $ as $ p i) | i <- r0n1])) Map.!)
        
        -- ancestor set excluding self
        asi :: Int -> Set Int
        asi i = Set.delete i $ as i
        
        -- ancestor sequence (list)
        al :: Int -> Seq Int
        al = ((Map.fromList (
            (0, Seq.singleton 0) :
            [(i, (Seq.|>) (al $ p i) i) | i <- r0n1])) Map.!)
        
        -- find lowest common ancestor
        lca :: Int -> Int -> Int
        lca x y = lca' x y 0 $ min (Seq.length $ al x) (Seq.length $ al y) where
            lca' x y a b
                | a+1 >= b  = (Seq.index (al x) a)
                | otherwise =
                    let c = (a+b) `quot` 2 in
                    let ss i = (Seq.index (al i) c) in
                    if ss x == ss y
                        then lca' x y c b
                        else lca' x y a c
        
        -- find Subset of a set Containing specified Range
        scr :: Int -> Int -> Set Int -> Set Int
        scr l r s =
            let
                (_, s1) = Set.split (l-1) s
                (s2, _) = Set.split (r+1) s1
            in s2
        
        -- find scr for ancestor of i
        scra :: Int -> Int -> Int -> Int
        scra l r i = Set.size (scr l r $ as i)
        
        scrai :: Int -> Int -> Int -> Int
        scrai l r i = Set.size (scr l r $ asi i)
        
        -- solve a query
        solve :: [Int] -> Int
        solve [x,y,l,r] =
            (scra' x) + (scra' y) - 2 * (scrai' z) - m
            where
                z = lca x y
                scra' = scra l r
                scrai' = scrai l r
                m = if Set.member z (scr l r $ as x)
                    then 1
                    else 0
        
    in
    mapM_ putStrLn $ map (show . solve) qs

