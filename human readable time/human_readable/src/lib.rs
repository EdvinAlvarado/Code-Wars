// fn make_readable(seconds: u32) -> String {
    // let s = seconds % 60;
    // let m = (seconds - s) / 60 % 60;
	// let h = (seconds - s - m*60) / (60*60);
	// return format!("{hor:0>2}:{min:0>2}:{sec:0>2}")
// }



fn make_readable(s: u32) -> String {
	let (m, s) = (s/60, s%60);
	let (h, m) = (m/60, m%60);
	return format!("{h:02}:{m:02}:{s:02}")
}





#[cfg(test)]
mod tests {
	use super::*;
    #[test]
    fn min_sec() {
        assert_eq!(make_readable(3600), "01:00:00");
    }
}
