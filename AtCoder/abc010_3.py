#                           जय श्री राम

import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

# sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")
def dsq(x1, y1, x2, y2):
    return math.sqrt((x1-x2)**2 + (y1-y2)**2)
# for _testcases_ in range(int(input())):
x1, y1, x2, y2, s, t = get_ints()
total = (s*t)
n = int(input())
flag = False
for _ in range(n):
    x3, y3 = get_ints()
    if dsq(x1, y1, x3, y3) + dsq(x2, y2, x3, y3) <= total:
        flag = True
        break
if flag:
    print("YES")
else:
    print("NO")


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''