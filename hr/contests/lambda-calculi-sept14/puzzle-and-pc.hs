type Coordinate = (Int, Int)
type Tromino = [Coordinate]
type Block = (Int,Coordinate,Coordinate) -- (n2, offset, missing)

solve' :: [Tromino] -> Block -> [Tromino]
solve' trominos block@(n2, (lr,lc), missing) =
    if n2 == 1
        then trominos'
        else foldl solve' trominos' children
    where
        mr = lr + n2
        ur = mr + n2
        mc = lc + n2
        uc = mc + n2
        
        quadrant :: Coordinate -> Int
        quadrant (r,c) =
            (if r < mr then 0 else 1) +
            (if c < mc then 0 else 2)
        
        center_tromino :: Tromino
        center_tromino =
            [(r,c) |
                r <- [mr-1,mr],
                c <- [mc-1,mc],
                quadrant (r,c) /= quadrant missing]
        
        children :: [Block]
        children =
            [let
                new_n2 = n2 `quot` 2
                offset = (dr, dc)
                missing_candidate = (r, c)
                new_missing =
                    if quadrant missing == quadrant missing_candidate
                        then missing
                        else missing_candidate
            
            in (new_n2, offset, new_missing) |
            (r, dr) <- [(mr-1, lr), (mr, mr)],
            (c, dc) <- [(mc-1, lc), (mc, mc)]]
        
        trominos' :: [Tromino]
        trominos' = center_tromino : trominos

solve :: Block -> [Tromino]
solve = solve' []

main :: IO ()
main =
    getLine >>= \ m_str ->
    let m = (read m_str :: Int) in
    getLine >>= \ rc_str ->
    let [r,c] = [(read x :: Int) - 1 | x <- words rc_str] in
    mapM_ putStr $ map tromino_string $ solve (2^(m-1), (0,0), (r,c))
    where
        tromino_string :: Tromino -> String
        tromino_string [] = "\n"
        tromino_string ((r,c):cs) =
            (show (r+1)) ++ " " ++ (show (c+1)) ++ " " ++ (tromino_string cs)

