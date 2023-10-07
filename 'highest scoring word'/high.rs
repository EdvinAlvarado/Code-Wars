
// ASSCI code a is 97. 
fn high(input: &str) -> &str {
    let score = |word: &str| -> usize {word.chars().map(|c| c as usize - 96).sum()};
    input.split_whitespace().rev().max_by_key(|word| score(word)).unwrap()
}

fn main() {
    println!("{}", high("aa b"));
}
