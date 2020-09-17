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
while True:
    n = int(input())
    if n == 0: break
    s = input()
    matr = []
    i = c = 0
    while i < len(s):
        if c & 1:
            matr.append(list(s[i:i+n][::-1]))
        else:
            matr.append(list(s[i:i+n]))
        i += n
        c += 1
    # print(matr)
    matr = list(zip(*matr))
    # print(matr)
    ans = ''
    for i in matr:
        this = ''.join(i)
        ans += this
    print(ans)


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''