'''     J A I ~ S H R E E ~ R A M     '''

# Title: mvita22.py
# created on: 18-07-2020 at 13:52:19
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
# 234 567 321 345 123 110 767 111
n = int(input())
li = list(input().split())
matr = [[0] * 2 for x in range(10)]
for i in range(n):
    num = li[i]
    score = (int(max(num)) * 11 + int(min(num)) * 7) % 100
    matr[score//10][i&1] += 1
    # print(score)
# print(matr)
ans = 0
for i in range(10):
    this = 0
    for j in range(2):
        if matr[i][j] == 2:
            this += 1
        elif matr[i][j] > 2:
            this += 2
    ans += min(this, 2)
print(ans)





'''
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here, otherwise.
'''
