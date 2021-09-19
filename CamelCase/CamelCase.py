def to_camel_case(text):
	import re
	r1 = re.findall(r"[A-Za-z]+", text)
	cameltext = ""
	for i in range(len(r1)):
		if i == 0:
			cameltext += r1[i]
		else:
			cameltext += r1[i][0].upper() + r1[i][1:]
	return cameltext


print(to_camel_case("the_stealth_warrior"))