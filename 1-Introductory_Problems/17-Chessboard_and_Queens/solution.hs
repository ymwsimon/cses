import Control.Monad (replicateM)
import Data.Sequence qualified as S
import Data.Foldable ( Foldable(toList) )

calWays :: [String] -> S.Seq Int -> Int -> Int
calWays m pos i =
  if i >= 8
    then 1
    else
      sum $ map f [0..7]
        where f j =
                let newPos = S.adjust' (const j) i pos
                    g (idx, p) = p /= j && p + (i - idx) /= j && p - (i - idx) /= j
                    validPos = m !! j !! i == '.' && all g (zip [0..] $ take i $ toList newPos) in
                  if validPos
                    then calWays m newPos $ i + 1
                    else 0

main :: IO ()
main = do
  m <- replicateM 8 getLine
  print $ calWays m (S.replicate 8 0) 0
