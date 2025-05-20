import Data.Set qualified as Set
import Data.Sequence qualified as Seq
import Control.Monad.Trans.State
import Control.Monad (foldM)
import Data.Foldable (Foldable(toList))

main :: IO ()
main = do
    n <- read <$> getLine
    putStrLn $ unlines $ map unwords
      $ evalState (genGrid 0 n) $ Seq.replicate n $ Set.fromAscList [0..(n * 10)]

genGrid :: Int -> Int -> State (Seq.Seq (Set.Set Int)) [[String]]
genGrid j n
  | j == n = pure []
  | otherwise = do
        row <- map show . fst
          <$> foldM doCol ([], Set.fromAscList [0..(n * 10)]) [0..(n - 1)]
        (row :) <$> genGrid (j + 1) n
              where doCol (prev, rs) i = do
                      cs <- gets ((!! i) . toList)
                      let num = Set.findMin $ Set.intersection rs cs
                      modify' $ Seq.adjust' (Set.delete num) i
                      pure (prev ++ [num], Set.delete num rs)