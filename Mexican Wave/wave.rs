fn wave(s: &str) -> Vec<String> {
    s.char_indices()
        .filter_map(|(i,c)| match c {
            ' ' => None,
            _ => Some(s[..i].to_string() + &c.to_uppercase().to_string() + &s[i+1..]),
        })
        .collect::<Vec<String>>()
}

fn main() {
    println!("{:?}", wave(" gap "));
}
