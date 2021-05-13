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





import random
def solveEachTest(_TestCase):
	# printsp("Case #{}: ".format(_TestCase)) 
	move = ['X', 'O', '_', 'X', 'O']
	for i in range(3):
		for j in range(3):
			printxsp(move[random.randint(0, 4)])
		print()






_T0T4 = random.randint(3, 8);
print(_T0T4)
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)
	print()



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

