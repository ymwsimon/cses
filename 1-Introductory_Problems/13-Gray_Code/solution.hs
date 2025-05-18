import Control.Monad.State
import Data.Foldable
import Data.Sequence as S
import Data.Bool

main :: IO ()
main = do
  n <- read <$> getLine
  evalStateT (genCode n 0) $ S.replicate n False

genCode :: Int -> Int -> StateT (Seq Bool) IO ()
genCode n i = do
  if i >= n
    then get >>= lift . putStrLn . map (bool '0' '1') . toList
    else do
      genCode n $ i + 1
      modify' $ adjust' not i
      genCode n $ i + 1
