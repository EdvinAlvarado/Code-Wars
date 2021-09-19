fn is_prime(x: i64) -> bool {
    if x < 0 {return false;}
    else if x==2 || x==3 || x==5 {return true;}
    else if x==1 {return false;}
    else if x%2 != 0 && x%3 != 0 && x%5 != 0 {return true;}
    false
}
