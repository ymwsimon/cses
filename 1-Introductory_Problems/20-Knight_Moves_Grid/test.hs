import Control.Monad
import Control.Monad.ST
import Data.Array.ST
import Data.Array.Unboxed
import Data.STRef
 
type Pos = (Int, Int)
type Grid s = STUArray s (Int, Int) Int
 
movDir :: [Pos]
movDir = [(1,2),(2,1),(-1,-2),(-2,-1),(1,-2),(-1,2),(2,-1),(-2,1)]
 
bfsSteps :: Int -> UArray (Int, Int) Int
bfsSteps n = runST $ do
  grid <- newArray ((0,0),(n-1,n-1)) (-1) :: ST s (Grid s)
  writeArray grid (0,0) 0
 
  let maxSize = n * n
  qx <- newArray (0, maxSize-1) 0 :: ST s (STUArray s Int Int)
  qy <- newArray (0, maxSize-1) 0 :: ST s (STUArray s Int Int)
  front <- newSTRef 0
  rear <- newSTRef 1
  writeArray qx 0 0
  writeArray qy 0 0
 
  let dequeue = do
        f <- readSTRef front
        modifySTRef' front (+1)
        x <- readArray qx f
        y <- readArray qy f
        pure (x, y)
 
      enqueue pos = do
        r <- readSTRef rear
        writeArray qx r $ fst pos
        writeArray qy r $ snd pos
        modifySTRef' rear (+1)
 
  let loop = do
        f <- readSTRef front
        r <- readSTRef rear
        when (f < r) $ do
          (x,y) <- dequeue
          d <- readArray grid (x,y)
          forM_ movDir $ \(dx,dy) -> do
            let nx = x + dx
                ny = y + dy
            when (nx >= 0 && ny >= 0 && nx < n && ny < n) $ do
              val <- readArray grid (nx,ny)
              when (val == -1) $ do
                writeArray grid (nx,ny) (d + 1)
                enqueue (nx,ny)
          loop
 
  loop
  freeze grid
 
main :: IO ()
main = do
  n <- readLn
  let arr = bfsSteps n
  forM_ [0..n-1] $ \i -> do
    let row = [ arr!(i,j) | j <- [0..n-1] ]
    putStrLn $ unwords (map show row)