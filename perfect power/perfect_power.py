from math import sqrt, log2, floor, ceil

def isPP(n):
	for m in range(2, ceil(sqrt(n))+1):
		print(m)
		for k in range(2, ceil(log2(n))+1):
			if m**k == n:
				print("{} {}".format(m, k))
				return (m, k)



x = isPP(81)

print(x)