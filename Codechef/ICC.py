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
	# g = groupby(input())
	# mx = 0; mxChar = '$'
	# for k, v in g:
	# 	v = len(list(v))
	# 	if v > mx:
	# 		mx = v
	# 		mxChar = k
	# print(mx, mxChar)

for _test_ in range(int(input())): 
	s = input()
	mx = 0; mxChar = '$'; prev = '$'; curr = 0
	for i in s:
		if i == prev:
			curr += 1
		else:
			curr = 1
		if curr > mx:
			mx = curr
			mxChar = i
		prev = i

	print(mx, mxChar)




