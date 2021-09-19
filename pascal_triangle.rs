fn pascals_triangle(n: usize) -> Vec<usize> {
    println!("{}", n);
    let mut results: Vec<Vec<usize>> = vec![vec![1;1];1];
    for nn in 1..n {
        let mut row: Vec<usize> = Vec::new();
        for k in 0..=nn {
            if k == 0 || k == nn {row.push(1);}
            else {row.push(results[nn-1][k-1] + results[nn-1][k]);}
        }
        results.push(row);
    }
    let mut flatten: Vec<usize> = Vec::new();
    for row in results.iter() {flatten.extend(row.iter());}
    flatten
}
