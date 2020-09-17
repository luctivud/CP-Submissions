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
def compute(A, X, a, b):
    x = ['0'] * 32
    y = ['0'] * 32
    A = bin(A)[2:].zfill(32)
    X = bin(X)[2:].zfill(32)
    # print(A, X, sep = '\n')
    for i in range(32):
        if A[i] == '1':
            x[i] = y[i] = '1'
            a -= (2**(32-i-1))
            b -= (2**(32-i-1))
        elif A[i] == '0' and X[i] == '1':
            if a >= b:
                x[i] = '1'
                y[i] = '0'
                a -= (2**(31-i))
            else:
                x[i] = '0'
                y[i] = '1'
                b -= (2**(31-i))
    ans1 = ans2 = ''
    
    for i in x:
        ans1 += i
    for i in y:
        ans2 += i
    # print(ans1, ans2)
    return [ans1, ans2]



n = int(input())
li = get_list()

S = li[0] + li[1]
try:
    X = reduce(lambda x, y: x ^ y, li[2:])
except:
    X = 0

A = (S - X) / 2
if A != math.floor(A):
    print('-1')
else:
    # print(A, X)
    x, y = compute(int(A), X, li[0], li[1])
    if x == -1:
        print(x)
    else:
        x = int(x, 2)
        y = int(y, 2)
        # print(x, y)
        x, y = min(x, y), max(x, y)
        if x > li[0]:
            print(-1)
        else:
            print(li[0] - x)

'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''