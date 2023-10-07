import qualified Data.Char as Char

wave :: String -> [String]
wave w = [take i w ++ [Char.toUpper $ w !! i] ++ drop (i+1) w | (i,c) <- zip [0..] w, c /= ' ']
