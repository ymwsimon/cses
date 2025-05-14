main :: IO ()
main = do
  n <- read <$> getLine :: IO Integer
  total <- sum . map read . words <$> getLine
  print $ div (n * (n + 1)) 2 - total