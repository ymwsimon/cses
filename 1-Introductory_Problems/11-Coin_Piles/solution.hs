import Control.Monad (forM_)

main :: IO ()
main = do
  n <- read <$> getLine :: IO Integer
  forM_ [1.. n] checkPile
    where checkPile _ = do
              [a, b] <- map read . words <$> getLine :: IO [Integer]
              if mod (a + b) 3 /= 0 || abs (a - b) > min a b
                then putStrLn "NO"
                else putStrLn "YES"