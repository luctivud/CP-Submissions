#				 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/					 #


import math;   		from collections import *
import sys;   		from functools import reduce
import time;   		from itertools import groupby

sys.setrecursionlimit(10**6)

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

def isvalid(i, j):
	global n
	global m
	return i >=0 and j >= 0 and i < n and j < m

def dfs(i, j, arr):
	global sz
	global visited
	if visited[i][j] or arr[i][j] == '0':
		return
	visited[i][j] = True
	sz += 1
	for xx, yy in DIRECTIONS:
		if isvalid(i+xx, j+yy):
			dfs(i+xx, j+yy, arr)



for _test_ in range(int(input())): 
	n, m = get_ints()
	arr = []
	for _ in range(n):
		arr.append(input())
	lands = []
	visited = [[False for y in range(m)] for x in range(n)]
	for i in range(n):
		for j in range(m):
			if not visited[i][j] and arr[i][j] == '1':
				sz = 0
				dfs(i, j, arr);
				lands.append(sz)
	lands.sort(reverse = True)
	# print(lands)
	ans = 0
	for i in range(len(lands)//2):
		ans += lands[2*i+1]
	print(ans);
	# print(visited)





