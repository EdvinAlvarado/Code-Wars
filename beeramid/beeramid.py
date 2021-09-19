def beeramid(bonus, price):
    l = 0
    tab = 0

    while tab + price * (l+1)**2 <= bonus:
        l += 1
        tab += price * l**2
    return l
