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
arr = get_list()
n = len(arr)
fwdSum = [arr[i] for i in range(n)]
bwdSum = [arr[i] for i in range(n)]

for i in range(1, n):
	fwdSum[i] = max(fwdSum[i], fwdSum[i-1]+arr[i])
for i in range(n-2, -1, -1):
	bwdSum[i] = max(bwdSum[i], bwdSum[i+1]+arr[i])

# print(fwdSum)
print(bwdSum)
try: ans = max(fwdSum[n-2], bwdSum[1])
except: ans = -float('inf')
for i in range(1, n-1):
	ans = max(ans, fwdSum[i-1]+bwdSum[i+1])
print(ans)




