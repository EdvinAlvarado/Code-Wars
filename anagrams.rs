fn anagrams(word: &str, words: &[String]) -> Vec<String> {
    let mut results: Vec<String> = Vec::new();

    let mut word_vec = word.chars().collect::<Vec<char>>();
    word_vec.sort_by(|a, b| b.cmp(a));
    let sorted_word: String = word_vec.iter().collect();

    for w in words.iter() {
        let mut w_vec = w.chars().collect::<Vec<char>>();
        w_vec.sort_by(|a, b| b.cmp(a));
        let sorted_w: String = w_vec.iter().collect();

        if sorted_word == sorted_w {results.push((&w).to_string());}
    }
    results
}
