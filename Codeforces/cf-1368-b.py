#                           जय श्री राम

import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

#sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")
# thanks omega01bot

# for _testcases_ in range(int(input())):
n = int(input())
ans = [1] * 10
this = 1; i = 0
while this < n:
    i %= 10
    this //= ans[i]
    ans[i] += 1
    this *= ans[i]
    i += 1
s = 'codeforces'
for i in range(10):
    print(s[i] * ans[i], end = "")
print()


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''