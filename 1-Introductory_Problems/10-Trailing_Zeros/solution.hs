main :: IO ()
main = do
  n <- read <$> getLine :: IO Integer
  print $ sum $ map (div n) $ takeWhile (<= n) fives
    where fives = scanl1 (*) $ repeat 5