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
string = input().strip()
explosion = input().strip()
explosion_size = len(explosion)
# print("ex", explosion_size)
stack = []
for i in string:
	stack.append(i)
	# print(stack)
	if len(stack) >= explosion_size:
		# print(stack, "".join(stack[-explosion_size:]))
		if ("".join(stack[-explosion_size:])) == explosion:
			for j in range(explosion_size):
				stack.pop()
	# print(stack)
if len(stack):
	print("".join(stack))
else:
	print("FRULA")





