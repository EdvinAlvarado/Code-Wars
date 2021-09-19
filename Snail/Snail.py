import numpy as np

def snail(array1):

	if len(array1) == 1:
		return array1[0]

	A = np.array(array1, dtype=np.uint16)
	total_steps = 2*len(A) - 1
	# print(total_steps)
	slist = []
	path = np.uint8(0)

	# print("initial")
	# print(A)

	for steps in range(total_steps):

		if path == 0:
			# # print(A[0])
			slist.extend(A[0])
			A = np.delete(A, 0, axis=0)
		elif path == 1:
			slist.extend(A[:, -1])
			A = np.delete(A, -1, axis=1)
		elif path == 2:
			slist.extend(np.flip(A, -1)[-1])
			A = np.delete(A, -1, axis=0)
		elif path == 3:
			slist.extend(np.flipud(A)[:, 0])
			A = np.delete(A, 0, axis=1)

		# print("Step {} \t path {}".format(steps, path))

		path += 1
		if path == 4:
			path = 0

		# print(A)
		# print(slist)

	return slist


arr = [[1, 2, 3], [8, 9, 4], [7, 6, 5]]

# print(snail(arr))