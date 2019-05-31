from math import sqrt, ceil
class Primes:
	@staticmethod
	def stream():
		yield 2
		n = 2
		while True:
			m = ceil(sqrt(n))
			fail = False
			while m >= 2:
				# not prime number
				if (n / m) % 1 == 0:
					fail = True
					break
				m -= 1

			if fail is False:
				yield n
			n += 1


for p in Primes.stream():
	print(p)
