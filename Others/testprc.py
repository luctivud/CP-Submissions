# class A:
# 	def __init__(self):
# 		pass
# 	def f(self):
# 		return 1
# 	def g(self):
# 		return self.f()
# a = A()
# print(a.g())

def fun(n):
	s = '+'
	for i in range(n):
		s += s
		yield s
for x in fun(2):
	print(x, end="")