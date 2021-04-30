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
	uni = get_list()
	val = get_list()
	d = {}
	for i in range(n):
		if uni[i] in d:
			d[uni[i]].append(val[i])
		else:
			d[uni[i]] = [val[i]]

	
	for ke, va in d.items():
		d[ke].sort(reverse = True)
		for j in range(1, len(d[ke])):
			d[ke][j] += d[ke][j-1]


	# print(d)



	ans = [0] * (n + 1)
	d = sorted(d.items(), key = lambda x : -len(x[1]))
	# print(d)
	N = len(d[0][1])
	# print(N, d[0][1])
	for i in range(1, N+1):
		for ke, va in d:
			sz = len(va)
			ind = ((sz // i) * i) - 1
			if ind != -1:
				ans[i] += va[ind]
			else:
				break
	print(*ans[1:])





