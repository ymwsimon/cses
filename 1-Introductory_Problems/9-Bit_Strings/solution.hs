main :: IO ()
main = do
  n <- read <$> getLine :: IO Integer
  print $ mod (2 ^ n) (1000000007 :: Integer)