# https://www.codewars.com/kata/weight-for-weight/train/python
def order_weight(strng):

	print(strng)
	if strng == '':
		return ''

	# nlist = strng.split(" ")
	# print(nlist)

	tuplelist = list(zip(strng.split(" "), [sum(int(d) for d in num) for num in strng.split(" ")]))
	# print(tuplelist)

	tuplelist = sorted(tuplelist, key=lambda tlist: tlist[1])
	print(tuplelist)

	# print("\n")
	for tpl in tuplelist:
		indices = [i for i, t in enumerate(tuplelist) if t[1] == tpl[1]]
		# print(indices)

		tuplegroups = [tuplelist[i] for i in indices]
		# tuplegroups = sorted(tuplegroups, key=lambda tlist: int(tlist[0][0]))
		tuplegroups = sorted(tuplegroups, key=lambda tlist: tlist[0])
		# print(tuplegroups)

		it = 0
		for i in indices:
			tuplelist[i] = tuplegroups[it]
			it += 1
		# print(tuplelist)

	return ' '.join([t[0] for t in tuplelist])


print(order_weight("2000 10003 1234000 44444444 9999 11 11 22 123"))