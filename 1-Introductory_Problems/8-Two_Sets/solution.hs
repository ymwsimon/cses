main :: IO ()
main = do
    n <- read <$> getLine :: IO Integer
    let total = div (n * (n + 1)) 2
    if odd total
      then putStrLn "NO"
      else putStr $ "YES\n" ++ showSizeContent (genList (div total 2 ) n ([], []))
        where
          genList target x (f, s)
            | x == 0 = (f, s)
            | target >= x = genList (target - x) (x - 1) (x : f, s)
            | otherwise = genList target (x - 1) (f, x : s)
          showSizeContent (f, s) =
            unlines
              [show $ length f,
              unwords $ map show f,
              show $ length s,
              unwords $ map show s]