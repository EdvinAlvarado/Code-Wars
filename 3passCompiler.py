# Tiny Three-Pass Compiler
import re

class Compiler(object):
	
	def compile(self, program):
		return self.pass3(self.pass2(self.pass1(program)))
		
	def tokenize(self, program):
		"""Turn a program string into an array of tokens.  Each token
		   is either '[', ']', '(', ')', '+', '-', '*', '/', a variable
		   name or a number (as a string)"""
		token_iter = (m.group(0) for m in re.finditer(r'[-+*/()[\]]|[A-Za-z]+|\d+', program))
		return [int(tok) if tok.isdigit() else tok for tok in token_iter]

	def pass1(self, program):
		"""Returns an un-optimized AST"""
		tokens = self.tokenize(program)
		pass
		
	def pass1(self, ast):
		"""Returns an AST with constant expressions reduced"""
		pass

	def pass3(self, ast):
		"""Returns assembly instructions"""
		pass


test = Compiler()
