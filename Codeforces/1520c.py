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


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (-1, -0)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]



# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

for _test_ in range(int(input())): 
	n = int(input())
	if n == 1:
		print(1)
	elif n == 2:
		print(-1)
	else:
		l = 1
		r = (((n**2) + 1) // 2) + 1
		# print("lr", l, r)
		for i in range(1, n+1):
			for j in range(1, n+1):
				if not ((i & 1) ^ (j & 1)):
					printsp(l)
					l += 1
				else:
					printsp(r)
					r += 1
			print()




