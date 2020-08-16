#				 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/					 #


import math;   		from collections import *
import sys;   		from functools import reduce
import time;   		from itertools import groupby

# sys.setrecursionlimit(10**6)

# def input()         : return sys.stdin.readline().strip()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (+1, -1)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]
from copy import copy

def solve(i, tup):
	print(i)
	if len(set(tup)) == 1 and tup[0] == 0:
		# print(i)
		return 1
	if i == n:
		return 0
	tupled_lis = tuple(tup)
	if tupled_lis not in dp[i]:
		arr2 = tup.copy()
		for j in lis[i]:
			arr2[ord(j)-ord('a')] -= 1
		# print(arr2 == tup)
		dp[i][tupled_lis] = max(solve(i+1, tup), solve(i+1, arr2))
	return dp[i][tupled_lis]




# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

# for _test_ in range(int(input())): 
s = input()
arr = [0] * 26
for i in s:
	arr[ord(i)-ord('a')] += 1
n = int(input())
lis = []
for _ in range(n):
	lis.append(input())
dp = [dict() for x in range(n)]
print(solve(0, arr))
# for d in dp:
# 	print(dp)




n = int(input())



