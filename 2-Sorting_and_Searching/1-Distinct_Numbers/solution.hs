import Data.Set qualified as S
import Control.Monad
import Data.Text.IO qualified as TIO
import Data.Text qualified as T

main :: IO ()
main = do
  void getLine
  nums <- T.words <$> TIO.getLine
  print $ S.size $ S.fromList nums
