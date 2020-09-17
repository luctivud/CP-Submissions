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
import copy
# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")

# for _testcases_ in range(int(input())):
r, c, k = get_ints()
matr = []
for i in range(r):
    matr.append(list(input()))
ans = 0
for i in range(2**r):
    for j in range(2**c):
        matrc = copy.deepcopy(matr)
        ii = bin(i)[2:].zfill(r)
        for indu in range(r):
            if ii[indu] == '1':
                matrc[indu] = ['r'] * c
        jj = bin(j)[2:].zfill(c)
        for indu in range(c):
            if jj[indu] == '1':
                for jks in range(r):
                    matrc[jks][indu] = 'r'
        temp = 0
        for ud in range(r):
            for it in range(c):
                if matrc[ud][it] == '#':
                    temp += 1
        if temp == k:
            ans += 1
        # print(ii, jj)
        # for irctc in matrc:
        #     print(*irctc)
print(ans)
        


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''