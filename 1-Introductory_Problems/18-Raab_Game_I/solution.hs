import Control.Monad (replicateM_)
import Data.Bool (bool)

main :: IO ()
main = do
  t <- read <$> getLine
  replicateM_ t solveGame
    where solveGame = do
            [n, a, b] <- map read . words <$> getLine :: IO [Int]
            bool (gameOK n a b) (putStrLn "NO")
              (a + b > n || a + b > 0 && max a b >= a + b)
              where gameOK n a b = 
                      let draw = [1..(n - (a + b))]
                          aList = take (a + b) $ reverse [1..n]
                          bList = take (a + b) $ drop b $ cycle aList in
                      do
                            putStrLn "YES"
                            putStrLn $ unwords $ map show $ aList ++ draw
                            putStrLn $ unwords $ map show $ bList ++ draw
                  