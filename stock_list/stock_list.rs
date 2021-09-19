use std::collections::HashMap;

fn stock_list(list_art: Vec<&str>, list_cat: Vec<&str>) -> String {
    if list_cat.len() == 0 || list_art.len() == 0 {return "".to_string();}
    let mut cat_values: HashMap<&str, u32> = HashMap::new();
    for art in list_art {
        let n: u32 = art.split(" ").nth(1).unwrap().parse().expect("not an unsigned int");
        *cat_values.entry(&art[0..1]).or_insert(0) += n;
    }
    let results: Vec<String> = list_cat.iter().map(|cat| format!("({} : {})", cat, cat_values.get(cat).unwrap_or(&0))).collect();
    results.join(" - ")
}
