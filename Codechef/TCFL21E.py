#				 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/					 #


import math;   		from collections import *
import sys;   		from functools import reduce
import time;   		from itertools import groupby

# sys.setrecursionlimit(10**6)

# def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (+1, -1)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]



# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

for _test_ in range(int(input())): 
	angle, limit = get_ints()
	ans = 0
	factor = 180 / angle
	ans = (limit / factor) - (2 / factor)
	zz = int(ans)
	zz1 = (limit-2)//2
	print(zz1 == zz, zz, zz1)
	# print(int(ans))

	# if angle == 90:
	# 	print((limit-2)//2)
	# else:
	# 	for i in range(3, limit+1):
	# 		Z = (180 / i)
	# 		cut = (angle / Z)
	# 		if cut <= (i-2) and abs(int(cut) - cut) <= 1e-6:
	# 			ans += 1
	# 	print(ans)






