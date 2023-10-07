import Data.List (maximumBy)
import Data.Char (ord)
import Data.Function (on)

score :: String -> Int
score = sum . (map (\c -> (ord c) - 96))

high :: String -> String
high = maximumBy (compare `on` score) . reverse . words

main = putStrLn $ high "aa b"
