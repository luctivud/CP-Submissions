#                           जय श्री राम

import sys; import math; from collections import *
from functools import reduce
sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e5)

#sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")


cache = {}

mod = 1000000009

def ans(n):
    if n in cache:
        return cache[n]

    if n == 0:
        cache[n] = 1
        return cache[n]
    if n == 1:
        cache[n] = 10
        return cache[n]

    temp1 = ans(n//2)
    temp2 = ans(n//2-1)

    if (n & 1) == 0:
        cache[n] = (temp1*temp1 - temp2*temp2) % mod
    else:
        temp3 = ans(n//2 + 1)
        cache[n] = (temp1 * (temp3 - temp2)) % mod

    return cache[n]

for _testcases_ in range(int(input())):
    n = int(input())
    print(ans(n % mod) % mod)



'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''