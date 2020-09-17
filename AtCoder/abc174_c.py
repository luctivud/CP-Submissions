'''     ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█  
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     '''


# [temp1.py] => [29-07-2020 @ 10:25:10] 
# Author & Template by : Udit "luctivud" Gupta
# https://www.linkedin.com/in/udit-gupta-1b7863135/


import math;   from collections import *
import sys;    from functools import reduce
import time;   from itertools import groupby

# sys.setrecursionlimit(10**6)

def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (+1, -1)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]


CAPS_ALPHABETS = {chr(i+ord('A')) : i for i in range(26)}
SMOL_ALPHABETS = {chr(i+ord('a')) : i for i in range(26)}
INF = float('inf')


# Custom input output is now piped through terminal commands.
# for _test_ in range(int(input())): 

n = int(input())
mod = int(1e9) + 7
if (n % 2 == 0):
	print(-1)
else:
	ans = -1
	num = 7
	for i in range(1, n+1):
		if num % n == 0:
			ans = i
			break
		num = (num % n * 10) % n + 7
	print(ans)




# print("Time Elapsed: {}".format(float(S34p-S34t)))
