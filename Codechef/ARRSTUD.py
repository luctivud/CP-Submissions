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

def isValid(i):
	if i < 0 or i >= n:
		return False
	return True


for _test_ in range(int(input())): 
	g = groupby(input())
	li = []
	ok = False
	for k, v in g:
		v = len(list(v));
		if k == '1':
			ok = True
		if ok:
			li.append(v)
		# print(k, v)
	# print(li)
	n = len(li)
	mx = max([li[2*i] for i in range(n//2)])
	# print(mx)

	for i in range(n//2):
		i = 2 * i
		if isValid(i+1) and li[i+1] == 1 and isValid(i+2) and (isValid(i-2) or isValid(i+4)):
			mx = max(mx, li[i] + li[i+2] + 1)
		elif (isValid(i-2) or isValid(i+2)):
			mx += 1
	print(mx)








