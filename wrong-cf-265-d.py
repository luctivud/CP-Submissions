#                          JAI SHREE RAM

import math; from collections import *
import sys; from functools import reduce

# sys.setrecursionlimit(10**6)
def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def get_string(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e5)

sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")

# for _testcases_ in range(int(input())):
n = int(input())
present = [False] * (MAXN+1)
li = get_list()
for i in li:
    present[i] = True
prime = [1] * (MAXN+1)
prime[0] = prime[1] = 0
for i in range(2, MAXN):
    if prime[i]:
        for j in range(2*i, MAXN, i):
            if present[j]:
                prime[i] += 1
            prime[j] = 0

fac = 1 if present[1] else 0
ans = 0
for i in range(MAXN):
    if prime[i]:
        ans = max(ans, prime[i] + fac)
print(ans)



'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''