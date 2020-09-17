'''     J A I ~ S H R E E ~ R A M     '''

# Title: cf-287353-c.py
# created on: 13-07-2020 at 16:34:21
# Creator & Template : Udit Gupta "@luctivud"
# https://github.com/luctivud
# https://www.linkedin.com/in/udit-gupta-1b7863135/


import math; from collections import *
import sys; from functools import reduce
from itertools import groupby

# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def get_string(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")


DIRECTIONS = [[0, 1], [0, -1], [1, 0], [1, -1]] #up, down, right, left
NEIGHBOURS = [(i, j) for i in range(-1, 2) for j in range(-1, 2) if (i!=0 or j!=0)]


OrdUnicode_a = ord('a'); OrdUnicode_A = ord('A')
CAPS_ALPHABETS = {chr(i+OrdUnicode_A) : i for i in range(26)}
SMOL_ALPHABETS = {chr(i+OrdUnicode_a) : i for i in range(26)}


MOD_JOHAN = int(1e9)+7; MOD_LIGHT = 998244353; INFINITY = float('inf')
MAXN_EYEPATCH = int(1e5)+1; MAXN_FULLMETAL = 501

# Custom input output is now piped through terminal commands.


# for _testcases_ in range(int(input())): 

n = int(input())
li = get_list()
start = end = -1
for i in range(n-1):
    if li[i] > li[i+1]:
        start = i
        break
for i in range(n-1, 0, -1):
    if li[i] < li[i-1]:
        end = i
        break
flag = True
if start == end == -1:
    print("yes")
    print(1, 1)
else:
    for i in range(start, end):
        if li[i] < li[i+1]:
            flag = False
            break;
    # print(start, end, "x")
    if end != n-1 and li[start] > li[end+1]:
        # print("ok1")
        flag = False
    if start != 0 and li[end] < li[start-1]:
        # print("ok2")
        flag = False
    if flag:
        print("yes")
        print(start+1, end+1)
    else:
        print("no")





'''
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here, otherwise.
'''
