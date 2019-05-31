# https://www.codewars.com/kata/5667e8f4e3f572a8f2000039/solutions/python
def accum(s):
	accumtext = ""
	return '-'.join(c.upper() + c.lower()*i for i, c in enumerate(s))


print(accum("ZpglnRxqenU"))