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
	# print((n & 1) ^ (len(bin(n)[2:]) & 1))
	n = bin(int(input()))[2:]
	num = (n.count('1')) & 1
	print(num ^ (len(n) & 1))


	# program for intuition
	# import random
	# N = random.randint(1, 5)
	# arr, binarr = [], []
	# for i in range(N):
	# 	arr.append(random.randint(1, 10))
	# 	binarr.append(list(map(int, (bin(arr[i])[2:]).zfill(64))))
	# n = functools.reduce(lambda x, y : x ^ y, arr)
	# numList = functools.reduce(lambda x, y: [x[i] + y[i] for i in range(64)], binarr)
	# num = functools.reduce(lambda x, y : x ^ y, numList)

	# print(N, arr)
	# for i in binarr:
	# 	print(i)
	# print(numList, "numList")
	# print(num, "num")
	# print(n)
	# print(bin(n)[2:])






_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

