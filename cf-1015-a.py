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
line = [0] * (m+2)
for i in range(n):
    a, b = get_ints()
    line[a] += 1
    line[b+1] -= 1
for i in range(1, m+2):
    line[i] += line[i-1]
# print(line)
ans = [i for i in range(1, m+1) if not line[i]]
print(len(ans))
print(*ans)


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''