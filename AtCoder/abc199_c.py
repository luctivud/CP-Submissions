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

# for _test_ in range(int(input())): 

n = int(input())
s = input()
li = [list(s[:n]), list(s[n:])]
q = int(input())

for qq in range(q):
	t, a, b = get_ints()
	if t == 2:
		li[0], li[1] = li[1], li[0]
	else:
		a -= 1
		b -= 1
		a0 = 0 if a < n else 1
		b0 = 0 if b < n else 1
		a1 = a % n
		b1 = b % n
		li[a0][a1], li[b0][b1] = li[b0][b1], li[a0][a1]

	# print(li)

print("".join(li[0]) + "".join(li[1]))
print(3**20)





