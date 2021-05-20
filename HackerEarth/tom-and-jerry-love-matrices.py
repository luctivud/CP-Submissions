''' 
	************************.- J A I  S H R E E  R A M -.*************************

	  ::: ---------- ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	      Author   :  Udit "luctivud" Gupta 

	      linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
	      github   :  https://github.com/luctivud

	  :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ---------- :::

'''

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





def solveEachTest(_TestCase):
	# printsp("Case #{}: ".format(_TestCase)) 
	n, m, x, q = Read_Ints()
	d = collections.OrderedDict()
	for i in range(2, n+m+1):
		d[i+x] = 0
	for i in range(1, n+1):
		for j in range(1, m+1):
			d[i+j+x] += 1
	for qq in range(q):
		query = Read_Array()
		if query[0] != 3:
			a, b, c = query[1:]
			for i in range(b, c+1):
				d[x+a+i] -= 1
				if d[x+a+i] == 0:
					del d[x+a+i]
		else:
			# print(d)
			a = query[1]
			cnt = 0
			res = -1
			for ke, va in d.items():
				if cnt + va >= a:
					res = ke
					break
				cnt += va
			print(res)

	






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

