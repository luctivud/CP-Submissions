'''     J A I ~ S H R E E ~ R A M     '''

# Title: cc-ORTHODOX.py
# created on: 19-07-2020 at 21:45:52
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


# def subarrayBitwiseOR(A): 
#     res = set()
#     pre = {0} 
#     for x in A: 
#         print(pre, {x})
#         pre = {x | y for y in pre} | {x} 
#         res |= pre 

#     return len(res) 


for _testcases_ in range(int(input())): 
    n = int(input())
    li = get_list()
    xo = set()
    xorsum = {0}

    for i in li:
        xorsum = {i | x for x in xorsum} | {i}
        xo |= xorsum

    print("YES" if len(xo) == (n*(n+1))//2 else "NO") 

  
# print required answer 



'''
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here, otherwise.
'''
