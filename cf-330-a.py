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

# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")

# for _testcases_ in range(int(input())):
n, m = get_ints()
rows = set(); cols = set()
matr = []
for i in range(n):
    matr.append(list(input()))
for i in range(n):
    for j in range(m):
        if matr[i][j] == 'S':
            rows.add(i)
            cols.add(j)
print(n*m - len(rows)*len(cols))



'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''