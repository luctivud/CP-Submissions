#                           जय श्री राम

import sys; import math; from collections import *
from functools import reduce
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

for _testcases_ in range(int(input())):
    n = int(input())
    c = 0
    for i in range(1, n):
        for j in range(i+1, n+1):
            if i ^ j <= n:
                c += 1
    print(c)



'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''