use regex::Regex;

// Create regex that takes any aplhabetical string
// Init our return camel_case
// init our switch to differentiate the first word that does not get uppercased
// loop to the capture struct where 0 will be the regex match and 1.. would be all the regex-group match (if specified)
// to uppercase just the first letter of each word:
// create a char iterator of the match str
// operate on the first char with next() and move the iterator forward
// if text is empty then return empty string
// else to_uppercase() returns a char iterator with the mapped uppercase
// chain behind it the rest of your c char iterator and collected in an implied String
// Then borrow the String to concactonated it to our return variable 
pub fn to_camel_case(text: &str) -> String {
    let re = Regex::new(r"[A-Za-z]+").unwrap();
    let mut camel_case: String = String::new();
    let mut first = true;
    for word in re.captures_iter(&text) {
        if first {
            camel_case += &word[0];
            first = false;
        }
        else {
            let mut c = word[0].chars();
            let upper_word: String = match c.next() {
                None => String::new(),
                Some(f) => f.to_uppercase().chain(c).collect(),
            };
            camel_case += &upper_word;
        }
    }
    return camel_case;
}
