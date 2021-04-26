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

mod = 1000000007;

def getSum(n):
	if n == 0: return 0
	return (n * (n+1) * pow(2, mod-2, mod)) % mod

def getSq(n):
	if n == 0: return 0
	return (n * (n+1) * (2*n+1) * pow(6, mod-2, mod)) % mod

for _test_ in range(int(input())): 
	l, r = get_ints()

	res1 = (getSum(r) - getSum(l-1))
	res1 = pow(res1, 2, mod)
	res2 = (getSq(r) - getSq(l-1))
	print((mod + res1 - res2) % mod)






