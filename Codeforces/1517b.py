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
	n, m = get_ints()
	arr = []
	ans = []
	for _ in range(n):
		arr.append(sorted(get_list()))
		ans.append(arr[-1].copy())
	# print(arr)
	# for i in arr:
	# 	print(i)

	l = [0 for _ in range(n)] 
	r = [m-1 for _ in range(n)]

	for j in range(m):	
		mn, mnInd = float('inf'), -1
		for i in range(n):
			if arr[i][l[i]] < mn:
				mn = arr[i][l[i]]
				mnInd = i
		# print(l, r)
		# print(mnInd, mn)
		for i in range(n):
			if i == mnInd:
				ans[i][j] = arr[i][l[i]]
				l[i] += 1
			else:
				ans[i][j] = arr[i][r[i]]
				r[i] -= 1
	
	for i in ans:
		print(*i)




