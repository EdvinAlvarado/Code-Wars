def zeros(n):
    if n < 5:
        return 0

    twos = 0
    fives = 0

    for i in filter(lambda x : x % 2 == 0 or x % 5 == 0 ,range(2, n+1)):
        while i % 2 == 0:
            twos += 1
            i //= 2
        while i % 5 == 0:
            fives += 1
            i //= 5
    
    return min(twos, fives)

print(zeros(10))
