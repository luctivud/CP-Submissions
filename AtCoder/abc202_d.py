#   J A I  S H R E E  R A M   #


import math, sys, collections, functools, time, itertools;

# sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


facto = [1]
for i in range(1, 61):
	facto.append(facto[-1] * i)

def getRes(a, b):
	return (facto[a+b] // facto[a]) // facto[b]

def solveEachTest(_TestCase):
	# printsp("Case #{}: ".format(_TestCase)) 
	# print(2**30)
	# print(math.factorial(60) // (math.factorial(30) * math.factorial(30)))
	a, b, k = Read_Ints()
	s = list('$' * (a+b))
	A, B = a, b

	# k -= 1

	for i in range(a+b):
		res1 = getRes(a-1, b)
		res2 = getRes(a, b-1)
		# print(i, res1, res2, "ir", a, b, k)
		if k <= res1 and a > 0:
			s[i] = 'a'
			a -= 1
		elif k <= res1 + res2:
			k -= res1
			s[i] = 'b'
			b -= 1
		else:
			assert(False)

	assert(s.count('a') == A and s.count('b') == B)

	print("".join(s))
	






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

