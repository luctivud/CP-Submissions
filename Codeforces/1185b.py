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

# def input()         : return sys.stdin.readline()
def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(get_ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>





def solveEachTest(_TestCase):
	# printsp("Case #{}: ".format(_TestCase)) 	
	N = int(input())
	for __ in range(N):
		a = list((ke, len(list(va))) for ke, va in itertools.groupby(input()))
		b = list((ke, len(list(va))) for ke, va in itertools.groupby(input()))
		# print(a, b)
		sz1, sz2 = len(a), len(b)
		if sz2 != sz1:
			print("NO")
		else:
			ok = True
			for i in range(sz1):
				if a[i][0] != b[i][0] or a[i][1] > b[i][1]:
					ok = False
					break
			print("YES" if ok else "NO")

	






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

