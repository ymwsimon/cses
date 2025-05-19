import Control.Monad (replicateM)
import Data.Bool (bool)

calWays :: [String] -> [(Int, Int)] -> Int -> Int
calWays m pos i =
  bool 1 (sum $ map iterNewPos [0..7]) (i < 8)
  where iterNewPos j = 
          let newPos = (length pos, j) : pos
              notAttack (idx, p) = notElem j [p, p + idxDiff, p - idxDiff]
                where idxDiff = i - idx
              validPos = m !! j !! i == '.' && all notAttack pos in
            bool 0 (calWays m newPos $ i + 1) validPos

main :: IO ()
main = do
  m <- replicateM 8 getLine
  print $ calWays m [] 0
