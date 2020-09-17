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

dp = [[i] for i in range(10)]
for i in range(10):
    this = (i * i)
    while (this % 10) != dp[i][0]:
        dp[i].append(this%10)
        this = (this%10)*i
for _testcases_ in range(int(input())):
    a, b = get_ints()
    if b == 0:
        ans = 1
    else:
        b -= 1
        ans = (dp[a%10][b%len(dp[a%10])])
    print(ans)
    # try:
    #     assert ans == (pow(a, b+1) % 10)
    #     print('True')
    # except:
    #     print('False')
'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''