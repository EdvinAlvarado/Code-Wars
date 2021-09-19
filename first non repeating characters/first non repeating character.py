def first_non_repeating_letter(string):
	print(string)
	dicletter = {}
	index = 0
	for c in string:
		if c.lower() not in dicletter:
			dicletter[c.lower()] = 1
		else:
			dicletter[c.lower()] += 1

		index += 1
	print(dicletter)

	for c in dicletter:
		if dicletter[c] == 1:
			return c
	return ""


x = first_non_repeating_letter("hello world, eh?")

print(x)