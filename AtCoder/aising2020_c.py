'''     J A I ~ S H R E E ~ R A M     '''

# Title: aising2020_c.py
# dated: 11-07-2020 17:43:44
# Creator & Template by : Udit Gupta @luctivud


import math; from collections import *
import sys; from functools import reduce

# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def get_string(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

DIRECTIONS = [[0, 1], [0, -1], [1, 0], [1, -1]] #up, down, right, left
NEIGHBOURS = [(i, j) for i in range(-1, 2) for j in range(-1, 2) if (i!=0 or j!=0)]

OrdUnicode_a = ord('a'); OrdUnicode_A = ord('A')
CAPS_ALPHABETS = {chr(i+OrdUnicode_A) : i for i in range(26)}
SMOL_ALPHABETS = {chr(i+OrdUnicode_a) : i for i in range(26)}

MOD_JOHAN = int(1e9)+7; MOD_LIGHT = 998244353; INFINITY = float('inf')
MAXN_EYEPATCH = int(1e5)+1; MAXN_FULLMETAL = 501

# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")

# for _testcases_ in range(int(input())): 
n = int(input())
ans = [0] * (n+1)
i = 1
while i * i < n:
    i += 1
n0001 = i+1
for i in range(1, n0001):
    for j in range(1, n0001):
        for k in range(1, n0001):
            e = (i**2) + (j**2) + (i*j) + (k**2) + (j*k) + (i*k)
            if e <= n:
                # print(i, j, k, e)
                ans[e] += 1

print(*ans[1:], sep="\n")




'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
'''
