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
	mod = 1000000007
	s, x = Read_Ints()
	a = (s - x);

	if (a & 1):
		print(-1)
		return
	else:
		a >>= 1

	xBits = bin(x)[2:].zfill(64)
	aBits = bin(a)[2:].zfill(64)

	xDash, yDash = "", "";
	for i in range(64):
		if xBits[i] == '0' and aBits[i] == '0':
			xDash += '0'
			yDash += '0'
		elif xBits[i] == '1' and aBits[i] == '1':
			print(-1)
			return
		elif xBits[i] == '0' and aBits[i] == '1':
			xDash += '1'
			yDash += '1'
		else:
			xDash += '0'
			yDash += '1'
	# print(xDash)
	# print(yDash)

	print((int(xDash, 2) * int(yDash, 2)) % mod)

	# ans = 0
	# for i in range(64):
	# 	if 
	# 	ans += pow(2, 63-i, mod)
	# 	ans %= mod
	






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

