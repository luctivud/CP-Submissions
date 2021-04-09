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

def solve(s, ind, res):
	if ind == -1 or len(res) > 3:
		return ""
	if dp[ind] != '$':
		return dp[ind];
	res2 = s[ind] + res
	if len(res2) == 3:
		if not (int(res2) % 8):
			dp[ind] = res2
			return res2
		else :
			res = ""
	dp[ind] = max(solve(s, ind-1, s[ind]+res), solve(s, ind-1, res))
	return dp[ind]


# for _test_ in range(int(input())): 
s = input()
n = len(s);
dp = ["$" for i in range(101)]
ans = solve(s, n-1, "")
print("YES\n"+ans if ans else "NO")




