'''     J A I ~ S H R E E ~ R A M     '''

# Title: cf-1385-d.py
# created on: 17-07-2020 at 20:59:55
# Creator & Template : Udit Gupta "@luctivud"
# https://github.com/luctivud
# https://www.linkedin.com/in/udit-gupta-1b7863135/


import math; from collections import *
import sys; from functools import reduce
from itertools import groupby

sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def get_string(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")


DIRECTIONS = [[0, 1], [0, -1], [1, 0], [1, -1]] #up, down, right, left
NEIGHBOURS = [(i, j) for i in range(-1, 2) for j in range(-1, 2) if (i!=0 or j!=0)]


OrdUnicode_a = ord('a'); OrdUnicode_A = ord('A')
CAPS_ALPHABETS = {chr(i+OrdUnicode_A) : i for i in range(26)}
SMOL_ALPHABETS = {i : chr(i+OrdUnicode_a) for i in range(26)}


MOD_JOHAN = int(1e9)+7; MOD_LIGHT = 998244353; INFINITY = float('inf')
MAXN_EYEPATCH = int(1e5)+1; MAXN_FULLMETAL = 501

# Custom input output is now piped through terminal commands.
def solver(l, r, sz, chatr):
    # global count
    # count += 1
    if sz == 0:
        if s[l] == SMOL_ALPHABETS[chatr]:
            return 0
        else:
            return 1
    # if dp[sz] == -1:
    cnt1 = cnt2 = 0
    for ind in range(l, l+sz):
        if s[ind] != SMOL_ALPHABETS[chatr]:
            cnt1 += 1
    for ind in range(r-sz, r):
        if s[ind] != SMOL_ALPHABETS[chatr]:
            cnt2 += 1
    # print(l, r, sz, chatr, cnt1, cnt2)
    zizzag = min(cnt1 + solver(r-sz, r, sz//2, chatr+1), cnt2 + solver(l, l+sz, sz//2, chatr+1))
    return zizzag

for _testcases_ in range(int(input())): 
    n = int(input())
    s = input()
    # l = 0; r = n//2;
    # current = 0
    # dp = [-1] * n
    # count = 0
    print(solver(0, n, n//2, 0))
    # print(dp)

    



'''
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here, otherwise.
'''
