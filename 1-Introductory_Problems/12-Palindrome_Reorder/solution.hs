import Data.List
import Data.Map.Strict qualified as M

main :: IO ()
main = do
  s <- getLine
  let freqMap = foldl' (\m x -> M.insertWith (+) x 1 m) M.empty s
  if M.size (M.filter odd freqMap) > 1
    then putStrLn "NO SOLUTION"
    else putStrLn $ makePalindrome freqMap
      where makePalindrome fm = 
              let oddChar = M.filter odd fm
                  oddCharString = M.foldlWithKey' (\l k r -> l ++ replicate r k) "" oddChar
                  evenChar = M.filter even fm
                  halfEvenChar = M.foldlWithKey' (\l k r -> l ++ replicate (div r 2) k) "" evenChar in
                    halfEvenChar ++ oddCharString ++ reverse halfEvenChar