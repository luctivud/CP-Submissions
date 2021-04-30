#				 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/					 #


# import math;   		from collections import *
# import sys;   		from functools import reduce
# import time;   		from itertools import groupby

# # sys.setrecursionlimit(10**6)

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
n = int(input())
a = get_list()
b = get_list()
matr = [[0 for y in range(n)] for x in range(n)]
for i in range(n):
	for j in range(n):
		matr[i][j] = a[j] * b[i]

trace = []
for i in range(n):
	if i:
		trace.append(trace[-1] + matr[i][i])
	else:
		trace.append(matr[i][i])


revTrace = [[0 for y in range(n)] for x in range(n)]
for j in range(n):
	i = 0
	prev = 0
	while (i < n) and j >= 0:
		revTrace[i][j] = prev + matr[i][j]
		prev = revTrace[i][j]
		j -= 1
		i += 1

for i in range(n-1, -1, -1):	
	j = n-1
	prev = 0
	while (i < n) and j >= 0:
		revTrace[i][j] = prev + matr[i][j]
		prev = revTrace[i][j]
		j -= 1
		i += 1


# print(trace, end="\n\n")

# for i in revTrace:
# 	print(i)


# print(matr)


ans = trace[-1]
for i in range(n):
	for j in range(i+1, n):
		res = 0
		if i > 0: res += trace[i-1]
		if j < n: res -= trace[j]
		res += trace[n-1]
		# print(res)
		# print(revTrace[j][i], revTrace[i-1][j-1])
		res += revTrace[j][i]
		if i-1>=0 and j+1< n: res -= revTrace[i-1][j+1]
		# print(i, j, res)
		ans = max(ans, res)
print(ans)




