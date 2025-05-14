main :: IO ()
main = do
  _ <- getLine
  nums <- map read . words <$> getLine :: IO [Integer]
  print $ sum $ zipWith (-) (scanl1 max nums) nums