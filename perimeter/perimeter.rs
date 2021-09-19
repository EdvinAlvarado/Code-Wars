// https://www.codewars.com/kata/559a28007caad2ac4e000083/train/c
fn perimeter(n: u64) -> u64 {
	let mut fib: [u64; 2] = [1, 1];
    let mut per: u64 = 2;
    if n == 0 {return 4;}
    else if n == 1 {return 8;}
    else {
        for _ in 2..=n {let temp: u64 = fib.iter().sum(); fib[0] = fib[1]; fib[1] = temp; per += temp;}
    }
	4 * per
}
