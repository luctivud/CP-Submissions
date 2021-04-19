#				 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/					 #


import math;   		from collections import *
import sys;   		from functools import reduce
import time;   		from itertools import groupby
import random

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
n, k = get_ints()
s = input()
c = sorted(Counter(s).items(), key = lambda x : -x[1])

li = []
i = 0
# print(c)
while (len(li) < k-1):
	ch = c[i][0];
	for ind, val in enumerate(s, 1):
		if val == ch and ind != n:
			li.append((ind, len(li)+1))
		if len(li) == k-1:
			break
	i += 1
li.append((n, k))
li.sort(key = lambda x : x[0])

for i in range(k):
	yo = li[i][0]
	print(yo, 1 if (i>0 and s[yo-1] == s[li[i-1][0]]) else 0)
# print(li)
print(*[i[1] for i in li])
# hairu = list(range(1, k+1))
# random.shuffle(hairu)
# print(*hairu)




# print(li)

# assert len(li)==k-1
# for i in li:
# 	print(i[0], 0)
# print(n, 0)
# for i in li:
# 	printsp(i[1])
# print(k)
# ihiei = list(range(1, n))