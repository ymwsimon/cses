import Data.List
main :: IO ()
main = do
  s <- getLine
  print $ maximum $ map length $ group s