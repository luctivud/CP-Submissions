#                          JAI SHREE RAM

import math; from collections import *
import sys; from functools import reduce

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def getlistofstring(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e5)

# sys.setrecursionlimit(10**6)
# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")

# for _testcases_ in range(int(input())):
N = int(input())
dp = [2] * (N+1)
dp[1] = 1
i = 2
while i < N:
    for j in range(2*i, N+1, i):
        dp[j] += 1
    i += 1
# print(dp[1:])
print(sum(i * dp[i] for i in range(1, N+1)))

'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''