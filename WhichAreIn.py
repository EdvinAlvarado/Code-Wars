def in_array(array1, array2):
	found = set()
	for ar2 in array2:
		for ar1 in array1:
			if ar2.find(ar1) != -1:
				found.add(ar1)
	foundlist = list(found)
	foundlist.sort()
	return foundlist


arr1 = ["arp", "live", "strong"]
arr2 = ["lively", "alive", "harp", "sharp", "armstrong"]
print(in_array(arr1, arr2))
