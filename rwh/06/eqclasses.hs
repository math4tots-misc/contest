class BasicEq a where
    isEqual :: a -> a -> Bool

class BasicEq3 a where
    isEqual3 :: a -> a -> Bool
    isEqual3 x y = not (isNotEqual3 x y)
    
    isNotEqual3 :: a -> a -> Bool
    isNotEqual3 x y = not (isEqual3 x y)

instance BasicEq Bool where
    isEqual True  True  = True
    isEqual False False = True
    isEqual _     _     = False

{-

Important Built-In Typeclasses

    Show
        'show' function converts value to String
        
        show :: (Show a) => a -> String

    Read
        opposite of Read,
        'read' function converts String to value
        
        read :: (Read a) => String -> a
    
    Equ
    
    Ord
    
    Bounded
    
    Enum
    
Note, builtin types are often "derivable", but custom typeclasses
are not.
-}
