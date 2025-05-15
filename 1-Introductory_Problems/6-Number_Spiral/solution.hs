import Control.Monad (forM_)

main :: IO ()
main = do
  n <- read <$> getLine :: IO Integer
  forM_ [1..n] solve
    where solve _ = do
            [row, col] <- map read . words <$> getLine :: IO [Integer]
            print $ let layer = max row col in
                      if even layer
                        then layer * layer - (layer - row) - (col - 1)
                        else layer * layer - (layer - col) - (row - 1)