

class Calculator(object):
	def evaluate(self, string):

		print(string)

		cmd = [int(s) if s.isdigit() else s for s in string.split(" ")]

		cmd = [float(s) if isinstance(s, str) and s.find('.') != -1 else s for s in cmd]

		print(cmd)

		for i in range(sum([1 if s == '*' or s == '/' else 0 for s in cmd])):
			for i, p in enumerate(cmd):
				if p == '*':
					cmd[i - 1] = cmd[i - 1] * cmd[i + 1]
					del cmd[i:i+2]
					break
				elif p == '/':
					cmd[i - 1] = cmd[i - 1] / cmd[i + 1]
					del cmd[i:i+2]
					break

		for i in range(sum([1 if s == '+' or s == '-' else 0 for s in cmd])):
			for i, p in enumerate(cmd):
				if p == '+':
					cmd[i - 1] = cmd[i - 1] + cmd[i + 1]
					del cmd[i:i+2]
					break
				elif p == '-':
					cmd[i - 1] = cmd[i - 1] - cmd[i + 1]
					del cmd[i:i+2]
					break

		return cmd[0]