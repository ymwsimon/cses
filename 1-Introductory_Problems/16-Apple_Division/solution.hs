import Data.Sequence qualified as S
import Control.Monad.Trans.State
import Data.Bool
import Data.Foldable

main :: IO ()
main = do
  n <- read <$> getLine
  nums <- map read . words <$> getLine :: IO [Int]
  print $ evalState (getMinDiff nums 0) $ S.replicate n False

getMinDiff :: [Int] -> Int -> State (S.Seq Bool) Int
getMinDiff nums i = do
  if i >= length nums
    then
       abs . sum . zipWith (*) nums . map (bool (-1) 1) . toList <$> get
    else
      do
        v <- getMinDiff nums $ i + 1
        modify' $ S.adjust' not i
        nv <- getMinDiff nums $ i + 1
        pure $ min v nv
