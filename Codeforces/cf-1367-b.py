#                           जय श्री राम

import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

MODPRIME = int(1e9+7); BABYMODPR = 998244353; MAXN = int(1e5)

# sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

for _testcases_ in range(int(input())):
    n = int(input())
    li = get_list()
    odd = even = 0
    for i in range(n):
        if i % 2 != li[i] % 2:
            if li[i] & 1:
                odd += 1
            else:
                even += 1
    if odd != even:
        print(-1)
    else:
        print(odd)


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''