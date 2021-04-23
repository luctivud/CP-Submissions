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

# se = set()
# for i in range(538*2):
# 	num = (math.cos(i * 0.71372437895816))
# 	ok = False
# 	for j in se:
# 		if abs(j-num) < 1e-5:
# 			ok = True
# 	se.add(num)
# 	if ok:
# 		print(ok, i)


# prev = 0
# for i in range(100):
# 	num1 = (math.cos(i * 0.71372437895816))
# 	num2 = (7 ** (i / 2))
# 	print((round(num1 * num2)))
# 	prev = round(num1 * num2) 


prev = 0
for i in range(20):
	num1 = 2 * (math.cos(i * 0.71372437895816))
	num2 = (7 ** (i / 2))
	num3 = (i * 4 ** i)
	ans = num3 + round(num1 * num2)
	print(prev+ans)
	prev = ans




