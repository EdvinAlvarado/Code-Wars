import re
def tokenize(program):

	token_iter = (m.group(0) for m in re.finditer(r'[-+*/()[\]]|[A-Za-z]+|\d+', program))
	return [int(tok) if tok.isdigit() else tok for tok in token_iter]

def pass1(tokens):

	var_pos = (tokens.index('['), tokens.index(']'))
	args = tokens[var_pos[0]+1:var_pos[1]]
	equation = tokens[var_pos[1]+1:]
	# print(args)

	return pass1_iterator(args, equation)

def pass1_iterator(args, tokens):

	if isinstance(tokens, list):

		# Gives the final iteration, the values themselves, into their proper form.
		# print("tokens {}".format(tokens))
		if len(tokens) == 1:
			tokens = tokens[0]
			if tokens in args:
				tokens = {'op': 'arg', 'n': args.index(tokens)}
			elif isinstance(tokens, int):
				tokens = {'op': 'imm', 'n': tokens}

			# print(tokens)
			return tokens

		# parenthesis handling
		# Use operators as nexus to seperate tokens before and after it and iterate through those respective token list.
		if '(' in tokens:
			if tokens.index('(') == 0 and tokens.index(')') == len(tokens) - 1:
				tokens.remove('(')
				tokens.remove(')')
				if '+' in tokens:
					nexus = tokens.index('+')
				elif '-' in tokens:
					nexus = tokens.index('-')
				elif '*' in tokens:
					nexus = tokens.index('*')
				elif '/' in tokens:
					nexus = tokens.index('/')
			else:
				if '+' in tokens[tokens.index(')')+1:]:
					nexus = tokens.index('+', tokens.index(')'))
				elif '-' in tokens[tokens.index(')')+1:]:
					nexus = tokens.index('-', tokens.index(')'))
				elif '*' in tokens[tokens.index(')')+1:]:
					nexus = tokens.index('*', tokens.index(')'))
				elif '/' in tokens[tokens.index(')')+1:]:
					nexus = tokens.index('/', tokens.index(')'))
		else:
			if '+' in tokens:
				nexus = tokens.index('+')
			elif '-' in tokens:
				nexus = tokens.index('-')
			elif '*' in tokens:
				nexus = tokens.index('*')
			elif '/' in tokens:
				nexus = tokens.index('/')
		# print("nexus: {} {}".format(nexus, tokens[nexus]))

		# Using the established nexus we make the two token lists before and after the op.
		a, b = [], []
		for i, t in enumerate(tokens):
			# print("index: {}\ttoken: {}".format(i, t))
			if i < nexus:
				a.append(t)
			elif i > nexus:
				b.append(t)

		# The iteration and format of the AST.
		result = {'op': tokens[nexus], 'a': pass1_iterator(args, a), 'b': pass1_iterator(args, b)}
		# print("final branch {}".format(result))
		return result
	else:
		PRINT("error")

def pass2(ast):
	return pass2_iterator(ast)

def pass2_iterator(ast):
	if 'n' not in ast:
		if ast['a']['op'] == 'imm' and ast['b']['op'] == 'imm':
			if ast['op'] == '*':
				return {'op': 'imm', 'n': ast['a']['n'] * ast['b']['n']}
			if ast['op'] == '+':
				return {'op': 'imm', 'n': ast['a']['n'] + ast['b']['n']}
			if ast['op'] == '-':
				return {'op': 'imm', 'n': ast['a']['n'] - ast['b']['n']}
			if ast['op'] == '/':
				return {'op': 'imm', 'n': ast['a']['n'] / ast['b']['n']}
		else:
			ast['a'] = pass2_iterator(ast['a'])
			ast['b'] = pass2_iterator(ast['b'])
			return ast
	# 'n' is in list
	else:
		return ast

def pass3(ast):
	R0 = 0
	R1 = 0
	stack = []
	result = []
	# result needs to be in R0
	
	

def simulate(asm, argv):
    r0, r1 = None, None
    stack = []
    for ins in asm:
        if ins[:2] == 'IM' or ins[:2] == 'AR':
            ins, n = ins[:2], int(ins[2:])
        if ins == 'IM':   r0 = n
        elif ins == 'AR': r0 = argv[n]
        elif ins == 'SW': r0, r1 = r1, r0
        elif ins == 'PU': stack.append(r0)
        elif ins == 'PO': r0 = stack.pop()
        elif ins == 'AD': r0 += r1
        elif ins == 'SU': r0 -= r1
        elif ins == 'MU': r0 *= r1
        elif ins == 'DI': r0 /= r1
    return r0


string = "[ x ] x + 2*5"
print(tokenize(string))
print(pass1(tokenize(string)))
print(pass2(pass1(tokenize(string))))

