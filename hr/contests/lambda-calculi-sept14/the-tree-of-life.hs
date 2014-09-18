import           Data.Map      (Map, (!))
import qualified Data.Map    as Map
import Text.ParserCombinators.ReadP

data Tree =
    Leaf Bool |
    Branch Bool Tree Tree
    deriving (Show, Eq)

type Rule = Map [Bool] Bool

logChar :: Char -> ReadP Char
logChar = ((>>) skipSpaces) . char

logSym :: ReadP Bool
logSym = choice (map logChar "X.") >>= return . (== 'X')

logLeaf :: ReadP Tree
logLeaf =
    logSym >>= \ b ->
    return (Leaf b)

logBranch :: ReadP Tree
logBranch =
    logChar '(' >>
    logTree >>= \ lhs ->
    logSym  >>= \ b ->
    logTree >>= \ rhs ->
    logChar ')' >>
    return (Branch b lhs rhs)

logTree :: ReadP Tree
logTree = logLeaf +++ logBranch

logPath :: Tree -> ReadP Tree
logPath t =
    let
    logPath' :: Tree -> ReadP Tree
    logPath' t =
        choice [
            char ']' >> (return t),
            choice (map char "<>") >>= \ c ->
            let Branch _ lhs rhs = t in
            logPath' (if c == '<' then lhs else rhs)]
    in
    logChar '[' >>
    logPath' t >>= \ subtree ->
    return subtree

parse :: ReadP a -> String -> a
parse p = fst . head . (readP_to_S p)

parse_tree :: String -> Tree
parse_tree = parse logTree

parse_path :: Tree -> String -> Tree
parse_path tree = parse (logPath tree)

parse_rule :: String -> Rule
parse_rule s =
    let rbs = n2bs 16 (read s :: Int)
    in  Map.fromList [(reverse $ n2bs 4 i, rbs !! i) | i <- [0..15]]

n2bs :: Int -> Int -> [Bool]
n2bs 0 i = []
n2bs n i = (rem i 2 == 1) : (n2bs (n-1) $ quot i 2)

node_state :: Tree -> Bool
node_state (Leaf b) = b
node_state (Branch b _ _) = b

node_data :: Bool -> Tree -> [Bool]
node_data b br@(Branch b3 l r) = [b, node_state l, b3, node_state r]
node_data b (Leaf b3) = [b, False, b3, False]

next_tree :: Rule -> Tree -> Tree
next_tree rule tree =
    let
    next_node :: Bool -> Tree -> Bool
    next_node b t = rule ! node_data b t
    
    next_tree' :: Bool -> Tree -> Tree
    next_tree' b t@(Leaf _) = Leaf (next_node b t)
    next_tree' b t@(Branch b1 l r) =
        Branch (next_node b t) (next_tree' b1 l) (next_tree' b1 r)
    
    in next_tree' False tree

tree_table :: Int -> Rule -> Tree -> Map Int Tree
tree_table lim rule tree =
    let
    tree_table' :: Map Int Tree
    tree_table' = Map.fromList $
        (0, tree) : [(i, next_tree rule $ tree_table' ! (i-1)) | i <- [1..lim]]
    in tree_table'

get_node_state :: Tree -> String -> Bool
get_node_state t s = node_state $ parse_path t s

get_node_char :: Tree -> String -> Char
get_node_char t s = if get_node_state t s then 'X' else '.'

solve :: Map Int Tree -> Int -> String -> Char
solve table pos query = get_node_char (table ! pos) query

main :: IO ()
main =
    getLine >>= \rule_str -> let rule = parse_rule rule_str in
    getLine >>= \tree_str -> let tree = parse_tree tree_str in
    getLine >>= \m_str -> let m = (read m_str :: Int) in
    let
    table :: Map Int Tree
    table = tree_table (m * 1000) rule tree
    
    solve_rest :: Int -> Int -> IO ()
    solve_rest m old_pos =
        if m == 0
            then return ()
            else
                getLine >>= \query_line ->
                let
                [dx_str, query] = words query_line
                dx = (read dx_str :: Int)
                new_pos = old_pos + dx
                in
                putStrLn ((solve table new_pos query):[]) >>
                solve_rest (m-1) new_pos
    
    in solve_rest m 0

