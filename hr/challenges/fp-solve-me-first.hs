main =
    let getInt = readLn :: IO Int in
    getInt >>= \a -> getInt >>= \b -> print $ a + b
