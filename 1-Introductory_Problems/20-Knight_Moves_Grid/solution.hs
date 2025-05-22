import Data.Sequence qualified as S
import Control.Monad.ST
import qualified Data.Array.ST as A
import Control.Monad
import Data.Text qualified as T
import Text.Show qualified as Sh
main :: IO ()
main = do
  n <- read <$> getLine :: IO Int
  let calStep = bfs n
  putStr $ T.unpack $ T.unlines $ map (T.unwords . map (T.pack . Sh.show)) calStep
    where bfs n = runST $
                do
                  grid <- A.newArray (0, n * n - 1) (-1) :: ST s (A.STUArray s Int Int)
                  A.writeArray grid 0 0
                  let step q = case S.viewl q of
                        S.EmptyL -> pure ()
                        (x, y) S.:< rest ->
                          do
                            xyStepVal <- A.readArray grid (x * n + y)
                            let nextStep = [(px, py)
                                  | (dx, dy) <- movDir
                                  , let px = dx + x , px >= 0, px < n
                                  , let py = dy + y , py >= 0, py < n]
                            newQ <- foldM (\acc (px, py) -> do
                              sVal <- A.readArray grid $ px * n + py
                              if sVal == -1 then A.writeArray grid (px * n + py) (1 + xyStepVal) >> pure (acc S.|> (px, py))
                              else pure acc) S.empty nextStep
                            step $ rest S.>< newQ
                  step $ S.singleton (0,0)
                  forM [0..n-1] $ \x -> forM [0..n-1] $ \y -> A.readArray grid (x * n + y)

movDir :: [(Int, Int)]
movDir = [(1,2),(2,1),(-1,-2),(-2,-1),(1,-2),(-1,2),(2,-1),(-2,1)]
