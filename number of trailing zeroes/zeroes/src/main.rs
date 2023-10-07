fn zeros(n: u64) -> u64 {
    let kmax = (n as f64).log(5.0) as u32;
    (1..=kmax).map(|k| n / 5u64.pow(k)).sum()
}

fn main() {
    for i in [1000, 10000, 1000000, 30, 14, 6, 1, 0] {
        println!("input:\t{}", i);
        println!("result\t{}\n", zeros(i));
    }
}
