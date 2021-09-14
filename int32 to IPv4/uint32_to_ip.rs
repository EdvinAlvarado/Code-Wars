
// My solution
fn ip(n: u32) -> String {
    let ar = n.to_be_bytes();
    return format!("{}.{}.{}.{}", ar[0],ar[1],ar[2],ar[3]);
}


// My favorite solution
use itertools::Itertools

fn int32_to_ip(n: u32) -> String {
    n.to_be_bytes().iter().join(".")
}
