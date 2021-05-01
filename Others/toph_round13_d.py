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
li = []
n = int(input())
months = ["jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "nov", "dec"]
for xx in range(n):
	s = input()
	month = months.index((s.split())[0][:3].lower())
	day = int((s.split())[1].strip(","))
	year = int((s.split(", "))[1])
	num = year * 10000 + month * 100 + day
	# print(num)
	li.append(num)

li.sort()

from bisect import bisect_left, bisect_right
q = int(input())
for qq in range(q):
	s = input()
	month = months.index((s.split())[0][:3].lower())
	day = int((s.split())[1].strip(","))
	year = int((s.split(", "))[1])
	num = year * 10000 + month * 100 + day
	# print(num)
	pos = bisect_left(li, num)
	# print(pos, li[pos])
	s = input()
	month = months.index((s.split())[0][:3].lower())
	day = int((s.split())[1].strip(","))
	year = int((s.split(", "))[1])
	num = year * 10000 + month * 100 + day
	pos2 = bisect_right(li, num)
	print(pos2 - pos)





