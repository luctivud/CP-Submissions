'''     J A I ~ S H R E E ~ R A M     '''

# Title: cc-CKOJ20B.py
# created on: 20-07-2020 at 20:23:03
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
n, k = get_ints()
li = sorted(get_list())
toCheck = set()
if n & 1:
   toCheck.add(li[n//2])
else:
    toCheck.update({li[n//2], li[n//2-1], (li[n//2]+li[n//2-1])//2})
# print(toCheck)
kaneki = sum(li)
toCheck.update({kaneki//n, (kaneki+n-1)//n})
# print(toCheck)
minSum = INFINITY
ans = -1
for i in toCheck:
    temp = 0
    for j in li:
        temp += abs((i-j)**k)
    if temp < minSum:
        minSum = temp
        ans = i
    elif temp == minSum:
        if i < ans:
            i =  ans
print(ans)



'''
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here, otherwise.
'''

