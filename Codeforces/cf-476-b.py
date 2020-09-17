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
def nCr(n, r):
    # print(n, r)
    if r == 1:
        return n
    if n == r:
        return 1
    r = max(r, n-r)
    ans = 1
    for i in range(r+1, n+1):
        ans *= i
    for i in range(1, n-r+1):
        ans //= i
    return ans

# for _testcases_ in range(int(input())):
s1 = input()
s2 = input()
p1 = s1.count('+') - s1.count('-')
p2 = s2.count('+') - s2.count('-')
avail = s2.count('?')
diff = abs(p1 - p2)
if diff > avail or (avail - diff) & 1:
    print("0.0")
else:
    val = diff + (avail - diff)//2
    print(nCr(avail, val)/(2**avail))



'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''