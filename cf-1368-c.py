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
n = int(input())
print(7*n+8)
flag = False
matr = [[1,1,1,0,0],[1,0,1,0,0],[1,1,1,1,1],[0,0,1,0,1],[0,0,1,1,1]]
for i in range(5):
    for j in range(5):
        if matr[i][j]:
            print(i, j)
fac = 4
n -= 1
while n>0:
    if n == 1:
        for i in range(3):
            for j in range(3):
                # print(matr[i][j], end=" ")
                if matr[i][j] and (i != 2 or j != 0):
                    print(i, j+fac)
    else:
        for i in range(5):
            for j in range(5):
                if matr[i][j] and (i != 2 or j != 0):
                    print(i, j+fac)
    n -= 2
    fac += 4


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''