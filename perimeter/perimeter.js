function perimeter(n) {
	let fib = new Array(n);
	let per = 0;

	for (let i = 0; i <= n; i++) {
		if (i == 0 || i == 1) {fib[i] = 1;}
		else {fib[i] = fib[i-1] + fib[i-2];}
		per += fib[i];
	}
	return 4*per;
}
