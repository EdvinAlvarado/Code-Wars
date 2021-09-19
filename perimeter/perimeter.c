// https://www.codewars.com/kata/559a28007caad2ac4e000083/train/c
typedef unsigned long long ull;
ull perimeter(int n) {
	ull per = 0;
	ull fib[n+1];
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == 1) {fib[i] = 1;}
		else {fib[i] = fib[i-1] + fib[i-2];}
		per += fib[i];
	}
	return 4 * per;
}
// ull fib(int n) {
// 	if (n == 0 || n == 1) {return 1;}
// 	else {return fib(n-1) + fib(n-2);}
// }


