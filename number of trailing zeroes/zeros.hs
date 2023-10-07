zeros :: Int -> Int
zeros 0 = 0
zeros n = z where
	kmax = floor $ logBase n 5
	z = sum [n / 5^k | k <- [1..kmax]]

 main = print $ [[x, zeros x] | x <- [0, 6, 30, 100, 1000]]
-- main = print $ zeros 30
