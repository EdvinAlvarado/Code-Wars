# https://www.codewars.com/kata/559a28007caad2ac4e000083/train/c
def perimeter(n):
    fib = []
    for i in range(n+1):
        if i == 0 or i == 1:
            fib.append(1)
        else:
            fib.append(fib[i-1] + fib[i-2])
    return 4 * sum(fib)
