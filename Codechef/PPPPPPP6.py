#                 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/                     #


import math;           from collections import *
import sys;           from functools import reduce
import time;           from itertools import groupby

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
def longestPalindrome(s):
    if (not s) or (not len(s)):
        return ""
    T = '#'.join('^{}$'.format(s))
    # print(T)
    n = len(T)
    P = [0] * n
    C = R = 0
    for i in range (1, n-1):
        P[i] = (R > i) and min(R - i, P[2*C - i])
        while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
            P[i] += 1
        if i + P[i] > R:
            C, R = i, i + P[i]
    maxLen, centerIndex = max((n, i) for i, n in enumerate(P))
    return s[(centerIndex  - maxLen)//2: (centerIndex  + maxLen)//2]



# for _test_ in range(int(input())): 
s = input()

print(longestPalindrome(s))




