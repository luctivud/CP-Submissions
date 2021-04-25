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
	n = int(input())
	s1 = input()
	s2 = input()
	even, odd = float('inf'), float('inf')
	if (s1[-1] == s2[-1]):
		even = 0
	else:
		odd = 0
	last1, last2 = 0, 0
	for i in range(n):
		if s1[i] != s1[-1]:
			last1 = i+1
		if s2[i] != s2[-1]:
			last2 = i+1
	if even == 0:
		odd = min(n-last1, n-last2)
	else:
		even = min(n-last1, n-last2)
	print(even, odd)





