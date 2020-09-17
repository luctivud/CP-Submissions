import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

# sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

# for _testcases_ in range(int(input())):
x1 = float(input())
y1 = float(input())
x2 = float(input())
y2 = float(input())
f  = float(input())
# Using differential calculus: 
ans = 0
mn = float('inf')
if x2 != x1:
    m = (x2-x1) / (y2-y1)
    start = x1 - m * y1
    end = x2
    if start > end:
        start, end = end, start
    # print(start, end)
    step = 0.000001
    end += step
    while start < end:
        x0 = start
        A = (x0-x1)
        B = (x2-x0)
        C = math.sqrt(y1**2+A**2)
        D = math.sqrt(y2**2+B**2)
        if abs((1/f)*(A/C) - (B/D)) < mn:
            mn = abs((1/f)*(A/C) - (B/D))
            ans = x0
        start += step
else:
    ans = x1
print("{0:.6f}".format(ans)) 
'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''