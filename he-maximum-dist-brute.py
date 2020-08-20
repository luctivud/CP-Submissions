#                           जय श्री राम

import sys; import math; from collections import *
from functools import reduce
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e5)

#sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

# for _testcases_ in range(int(input())):
n = int(input())
li = get_list()
for _ in range(int(input())):
    query = get_list()
    if query[0] == 1:
        l, r, x = query[1]-1, query[2], query[3]
        for j in range(l, r):
            li[j] += x
    elif query[0] == 2:
        l, r, x = query[1]-1, query[2], query[3]
        for j in range(l, r):
            li[j] *= x
    else:
        x = query[1]
        start, end = n, -1
        for j in range(n):
            if li[j] == x:
                start = min(start, j)
                end = max(end, j)
        if (end < start) :
            print("-1")
        else:
            print(end - start + 1)




'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''