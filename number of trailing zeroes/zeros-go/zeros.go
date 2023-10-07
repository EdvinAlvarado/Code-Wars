package main

import "fmt"
import "math"

func Logb(val, base float64) float64 {
	return math.Log10(val) / math.Log10(base)
}

func Zeros(n int) int {
	if n == 0 {return 0}
	kmax := int(math.Floor(Logb(float64(n), 5)))
	z := 0
	for k := 1; k <= kmax; k++ {
		z += n / int(math.Pow(5, float64(k)))
	}
	return z
}


func main() {
	arr := []int{0, 6, 14, 30, 1000}
	for _,i := range arr {
		fmt.Println(Zeros(i))
	}
}

