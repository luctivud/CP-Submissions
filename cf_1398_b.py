import math;   		from collections import *
import sys;   		from functools import reduce
import time;   		from itertools import groupby

# sys.setrecursionlimit(10**6)

def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

for _test_ in range(int(input())): 
	s = input()
	g = groupby(s)
	bits = []
	for ke, val in g:
		if ke == '1':
			val = list(val)
			bits.append(len(val))
	bits.sort(reverse = True)
	ans = 0
	for i in range(len(bits)):
		if not (i & 1):
			ans += bits[i]
	print(ans)