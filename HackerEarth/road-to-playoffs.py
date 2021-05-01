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

for _test_ in range(int(input())): 
	n, m, k, b = get_ints()
	arr = get_list()
	arr.sort()
	# m = m * ((2*k + n - 1) // n)
	l, r, ans = 0, n-1, -1
	# assert (k <= n//2) or (n & 1)
	while l <= r:
		mid = (l + r) >> 1
		brr = arr.copy()
		brr[mid] += m;
		remainingPoints = (m * (k-1));
		ind = 0
		while ind < mid and remainingPoints > 0:
			mx = min(remainingPoints, brr[mid] - brr[ind], m)
			remainingPoints -= mx
			brr[ind] += mx
			ind += 1
		ind = mid + 1
		while ind < n and remainingPoints > 0:
			mx = min(remainingPoints, brr[mid] - brr[ind], m)
			remainingPoints -= mx
			brr[ind] += mx
			ind += 1
		ind = n - 1
		while ind >= 0 and remainingPoints > 0:
			mx = min(remainingPoints, m-(brr[ind] - arr[ind]));
			brr[ind] += mx;
			remainingPoints -= mx;
			ind -= 1
		res = 0
		for i in brr:
			res += (i > brr[mid]);
		if res >= b:
			ans = max(ans, mid)
			l = mid + 1
		else:
			r = mid - 1
		print(brr, mid, remainingPoints)
	print(n-ans-1)
