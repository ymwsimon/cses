main :: IO ()
main = do
  n <- read <$> getLine :: IO Integer
  putStrLn $ if n == 2 || n == 3
                then "NO SOLUTION"
                else unwords $ map show $ [2,4..n] ++ [1,3..n]