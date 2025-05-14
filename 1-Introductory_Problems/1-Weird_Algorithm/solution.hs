main :: IO ()
main = do
    n <- read <$> getLine
    putStrLn $ unwords $ map show $ genListNum n
        where   genListNum :: Integer -> [Integer]
                genListNum x
                    | x == 1 = [1]
                    | even x = x : genListNum (div x 2)
                    | otherwise = x : genListNum (x * 3 + 1)