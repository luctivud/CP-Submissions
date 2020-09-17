#                           जय श्री राम

import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

# sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

# for _testcases_ in range(int(input())):
s = input()
i, count, prev = 1, 1, s[0]
while i < len(s):
    if s[i] != prev:
        printspx(prev+str(count))
        prev = s[i]; count = 1
    elif s[i] == prev:
        count += 1
    i += 1
print(prev+str(count))

'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''