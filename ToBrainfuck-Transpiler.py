import re
from math import floor
from copy import deepcopy


class bf:

	# The length of a list will always be in range [1,256].
	def __init__(self, *args, **kwargs):
		# super(bf, self).__init__(*args, **kwargs)
		self.data = {}
		self.proc_cmd = []

	def cmd_prsr(self, cmdstr):
		cmd = []
		for var in re.findall(r'[^\s]+', cmdstr):
			cmd.append(var)
		# return cmd
		# Make upper vars
		cmd = [cmd[0]] + [c.upper() for c in cmd[1:]]
		cmd[0] = cmd[0].lower()
		# print(cmd)

		# Increase tolerance of array declaration. x [ 10 ] -> x[10]
		remlist = []
		for i, s in enumerate(cmd):
			# print(cmd)
			if re.match(r'\[[0-9]\]', s) is not None:

				cmd[i-1] = cmd[i-1] + s
				cmd.pop(i)

			elif re.match(r'\[$', s) is not None:

				end = [re.match(r'\]', s) is not None for s in cmd].index(True)
				cmd[i-1] = ''.join(cmd[i-1:end+1])
				for j in range(i, end+1):
					remlist.append(cmd[j])

		for r in remlist:
			cmd.remove(r)
		print(cmd)
		print(self.proc_cmd)

		if sum([1 if c in ['ifeq', 'ifneq', 'wneq', 'proc'] else 0 for c in self.proc_cmd]) != sum([1 if c == 'end' else 0 for c in self.proc_cmd]):

			self.proc_cmd.extend(cmd)

		elif self.proc_cmd == []:

			if cmd[0] == 'var':
				self.var(cmd[1:])
			elif cmd[0] == 'set':
				self.set(cmd[1], cmd[2])
			elif cmd[0] == 'inc':
				self.inc(cmd[1], cmd[2])
			elif cmd[0] == 'dec':
				self.dec(cmd[1], cmd[2])
			elif cmd[0] == 'add':
				self.add(cmd[1], cmd[2], cmd[3])
			elif cmd[0] == 'sub':
				self.sub(cmd[1], cmd[2], cmd[3])
			elif cmd[0] == 'mul':
				self.mul(cmd[1], cmd[2], cmd[3])
			elif cmd[0] == 'divmod':
				self.divmod(cmd[1], cmd[2], cmd[3], cmd[4])
			elif cmd[0] == 'div':
				self.div(cmd[1], cmd[2], cmd[3])
			elif cmd[0] == 'mod':
				self.mod(cmd[1], cmd[2], cmd[3])
			elif cmd[0] == 'cmp':
				self.cmp(cmd[1], cmd[2], cmd[3])
			elif cmd[0] == 'msg':
				self.msg(*cmd[1:])
			elif cmd[0] == 'read':
				self.read(cmd[1])
			elif cmd[0] == 'b2a':
				self.b2a(cmd[1], cmd[2], cmd[3], cmd[4])
			elif cmd[0] == 'a2b':
				self.a2b(cmd[1], cmd[2], cmd[3], cmd[4])
			elif cmd[0] == 'lset':
				self.lset(cmd[1], cmd[2], cmd[3])
			elif cmd[0] == 'lget':
				self.lget(cmd[1], cmd[2], cmd[3])
			elif cmd[0] in ['ifeq', 'ifneq', 'wneq', 'proc']:
				self.proc_cmd.extend(cmd)
		# impliceitly filled and completed
		else:

			if cmd[0] == 'ifeq':
				self.ifeq(cmd[1], cmd[2], cmd[3:])
			if cmd[0] == 'ifneq':
				self.ifneq(cmd[1], cmd[2], cmd[3:])



			self.proc_cmd.clear()

	# consider making it *args
	# set limit to 256
	def var(self, args):
		array_detector = [re.match(r'[A-z]\[[0-9]+\]', i) is not None for i in args]
		# spaced_array_detector = [re.match(r'\[[0-9]+\]', i) is not None for i in args]

		# print(args)
		# print("array declared\t{}\narray spaced\t{}".format(array_detector, spaced_array_detector))

		for i, arg in enumerate(args):
			if array_detector[i]:
				# if array_detector[i]:
				self.data[arg[0]] = [0 for i in range(int(re.findall(r'[0-9]+', arg)[0]))]
				# else:
				# 	self.data[args[i-1]] = [0 for i in range(int(re.findall(r'[0-9]+', arg)[0]))]
			else:
				self.data[arg] = 0

	def prsr(self, val):
		# char to int; 'X' -> 88
		if re.match(r'\'[A-z]\'', val):
			return ord(val[1])
		# variable
		elif re.match(r'[A-z]', val):
			return self.data[val]
		# val
		elif re.match(r'-[0-9]+|[0-9]+', val):
			return int(val) % 256

	def set(self, reg, val):
		self.data[reg] = self.prsr(val)

	def inc(self, reg, val):
		self.data[reg] += self.prsr(val)

	def dec(self, reg, val):
		self.data[reg] -= self.prsr(val)

	def add(self, val1, val2, reg):
		self.data[reg] = self.prsr(val1) + self.prsr(val2)

	def sub(self, val1, val2, reg):
		self.data[reg] = self.prsr(val1) - self.prsr(val2)

	def mul(self, val1, val2, reg):
		self.data[reg] = self.prsr(val1) * self.prsr(val2)

	# Divisor will not be 0
	def divmod(self, val1, val2, reg1, reg2):
		a = self.prsr(val1)
		b = self.prsr(val2)
		self.data[reg1] = floor(a / b)
		self.data[reg2] = a % b

	def div(self, val1, val2, reg):
		self.data[reg] = floor(self.prsr(val1) / self.prsr(val2))

	def mod(self, val1, val2, reg):
		self.data[reg] = self.prsr(val1) % self.prsr(val2)

	def cmp(self, val1, val2, reg):
		# If a < b store -1(255) charo c.
		# If a == b store 0 charo c.
		# If a > b store 1 charo c.
		a = self.prsr(val1)
		b = self.prsr(val2)

		if a < b:
			self.data[reg] = 255
		elif a == b:
			self.data[reg] = 0
		elif a > b:
			self.data[reg] = 1

	# ascii digits should be turned charo their assvi values or their char values?
	def a2b(self, val1, val2, val3, reg):
		a = self.prsr(val1)
		b = self.prsr(val2)
		c = self.prsr(val3)
		self.data[reg] = 100*(a-48) + 10*(b-48) + (c-48)

	def b2a(self, val, reg1, reg2, reg3):
		a = self.prsr(val)
		self.data[reg1] = 48 + floor(a / 100)
		self.data[reg2] = 48 + floor(a / 10 % 10)
		self.data[reg3] = 48 + (a % 10)

	# IndexError will not be evaluated
	def lset(self, reg, i, val):
		self.data[reg][self.prsr(i)] = self.prsr(val)

	def lget(self, arr, i, reg):
		self.data[reg] = self.data[arr][self.prsr(i)]

	def msg(self, *args):
		lst = [str(self.data[arg]) if arg in self.data.keys() else arg for arg in args]
		print(''.join(lst))

	def read(self, val):
		print(self.prsr(val))

	def ifeq(self, val1, val2, body):
		if self.prsr(val1) == self.prsr(val2):
			print(body)

	def ifneq(self, val1, val2, body):
		if self.prsr(val1) != self.prsr(val2):
			print(body)


def kcuf(code):
	b = bf()
	for line in re.findall(r'[^\n]+', code):

		print(line)
		b.cmd_prsr(line)
		print(b.data)
		print("-------")


# make case insensitive


# kcuf("""
# var F L[5] X
# set F 0
# add 10 10 X
# wneq F 5
# 	lset L F X
# 	inc F 1
# 	dec X 1
# end
# //L == [20,19,18,17,16]

# wneq F 0
# 	inc F -1
# 	lget L F X
# 	msg X
# end

# set F 10
# wneq F 0
# 	ifeq F 10
# 		set F 5
# 	end
# 	dec F 1
# 	lget L F X
# 	ifneq X 18
# 		msg F X
# 	end
# end
# ifeq F 0
# 	ifneq X 50
# 		msg ";-)"
# 	end
# end
# """)

kcuf("""
ifeq 0 0
	msg 'X'
end

""")