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

# for _test_ in range(int(input())): 
n, m = get_ints()
li = []
for i in range(n):
	op, t = input().split()
	li.append((op, int(t)))
# print(li)
ans = 0
for i in range(32, -1, -1):
	num = 1 << i
	# print(num)
	for op, t in li:
		if op == 'AND':
			num &= t
		elif op == 'OR':
			num |= t
		else:
			num ^= t
	print(num, i)
	print(bin(num)[2:].zfill(32))
	if (i):
		num >>= (i-1)
	# print((num & 1), i)
	print(bin(num)[2:])
	if (num & 1) and (ans + (1 << i)) <= m:
		ans += 1 << i

	# if num > mx:
	# 	mx = num
	# 	break

print(ans)





