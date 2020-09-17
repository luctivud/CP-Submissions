'''     J A I ~ S H R E E ~ R A M     '''

# Title: cf-CLBRKT.py
# created on: 15-07-2020 at 21:44:49
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


for _testcases_ in range(int(input())): 
    s = input()
    n = len(s)
    # q = int(input())
    # queries = get_list()
    stack = []
    num_eq = [0]
    for i in s:
        if i == ')':
            if len(stack) == 0:
                num_eq.append(0)
            else:
                num_eq.append(num_eq[-1]-1)
                stack.pop()
        else:
            num_eq.append(num_eq[-1]+1)
            stack.append('(')
    print(num_eq)
    l = r = 1
    ans = [-1] * (n+1)
    while r <= n:
        printsp(l, r)
        if num_eq[r] > num_eq[r-1]:
            if num_eq[r-1] > 0:
                l += 1
            r += 1
        elif num_eq[r] < num_eq[r-1]:
            # printsp("ok")
            ans[l] = r
            if num_eq[r] == 0:
                l = r+1
            else:
                l -= 1
            r += 1
        elif num_eq[r] == 0:
            r += 1
            l = r
        print(ans[1:])
    touka = -1
    for i in range(n, 0, -1):
        if s[i-1] == '(':
            if touka == -1:
                touka = ans[i]
            else:
                touka = ans[i]
        else:
            ans[i] = touka
        # print(i, touka, s[i-1])
    
    print(ans[1:])
    # for qq in queries:
    #     print(ans[qq])







'''
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here, otherwise.
'''
