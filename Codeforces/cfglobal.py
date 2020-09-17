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


# def traverse(i, j, num):
# 	if i == n or k == n:
# 		return
# 	if matr[i][j] == 0:
# 		matr[i][j] = 


def traverse(i, j, num, totalSum):
	# print(i, j, num, totalSum)
	if i == n-1 and j == n-1:
		totalSum += matr[i][j]
		if totalSum in dp:
			print("found", totalSum)
		dp[totalSum] = num
	if i >= n or j >= n :
		return
	traverse(i+1, j, num * 2, totalSum+matr[i][j])
	traverse(i, j+1, num * 2 + 1, totalSum + matr[i][j])


# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

# for _test_ in range(int(input())): 
n = int(input())
matr = [[0 for x in range(n)] for y in range(n)]
# print(matr)
ans = dict()
fac = 0
# print(matr)
dp = dict()
for i in range(n):
	for j in range(n):
		matr[i][j] = 2 ** j 
		fac+=1
		printsp(matr[i][j])
	print()
traverse(0, 0, 0, 0)
# print(dp[10])
# print(matr)
# print(max(dp))
print(dp)
# for qq in range(int(input())):
# 	k = int(input())
# 	x = 1
# 	y = 1
# 	path = dp[k]
# 	print(bin(path)[2:].zfill(n+1))
# 	for i in bin(path)[2:].zfill(n+1):
# 		if i == '0':
# 			pass






