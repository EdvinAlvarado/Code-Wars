beeramid :: Double -> Double -> Int
beeramid b p = length [x | x <- scanl1 (+) [p * l^2 | l <- [1..b]], x <= b]

-- Favorite solution
beeramid b p = length $takeWhile (<=b) $ scanl1 (+) [p*n^2 | n<-[1..]]
