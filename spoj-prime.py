#                          JAI SHREE RAM

import math; from collections import *
import sys; from functools import reduce

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def getlistofstring(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e9)

# sys.setrecursionlimit(10**6)
sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")
prime = [True] * MAXN

prime[0] = prime[1] = False
i = 2
while i * i < MAXN:
    if prime[i]:
        for j in range(2*i, MAXN, i):
            prime[j] = False
    i += 1

for _testcases_ in range(int(input())):
    l, r = get_ints()
    for i in range(l, r+1):
        if prime[i]:
            print(i)
    print()

'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''