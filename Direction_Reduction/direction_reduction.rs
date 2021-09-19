#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum Direction {
    North,
    East,
    West,
    South
}

// My Solution
fn dir_reduc(arr: &[Direction]) -> Vec<Direction> {
    println!("\n{:?}", arr);
    let mut tvec = arr.to_vec();

    for _ in 0..arr.len() {
        if tvec.len() == 0 {return tvec;}
        'remove: for i in 0..tvec.len()-1 {
            if (tvec[i] == Direction::North && tvec[i+1] == Direction::South) 
                || (tvec[i] == Direction::South && tvec[i+1] == Direction::North)
                || (tvec[i] == Direction::West && tvec[i+1] == Direction::East)
                || (tvec[i] == Direction::East && tvec[i+1] == Direction::West) {
                
                tvec.remove(i);
                tvec.remove(i);
                break 'remove;
            }
        }
    }

    println!("{:?}", tvec);
    tvec
}


// Favorite Solution
// only one for loop
fn dir_reduc(arr: &[Direction]) -> Vec<Direction> {
    let mut stack = vec![];
    for &dir in arr.iter() {
        match (dir, stack.last()) {
            (Direction::North, Some(Direction::South))
            | (Direction::South, Some(Direction::North))
            | (Direction::East, Some(Direction::West))
            | (Direction::West, Some(Direction::East)) => {
                stack.pop();
            }
            _ => stack.push(dir),
        }
    }
    stack
}
