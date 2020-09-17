'''     J A I ~ S H R E E ~ R A M     '''

# Title: cc-CLLEXO.py
# created on: 15-07-2020 at 23:31:00
# Creator & Template : Udit Gupta "@luctivud"
# https://github.com/luctivud
# https://www.linkedin.com/in/udit-gupta-1b7863135/


import math; from collections import *
import sys; from functools import reduce
# from itertools import groupby

sys.setrecursionlimit(10**6)

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

# Custom input output is now piped through terminal commands.

def greedyDFS(i, j, n, m, ans):
    # print(i, j, ans)
    if i >= n or j >= m:
        return -1
    if i == n-1 and j == m-1:
        print(matr[0][0] + ans)
        return
    if dp[i][j] == 0:
        return 0
    if dp[i][j] == -1:
        # print(i, j, matr[i][j])
        if i + 1 < n: cmp1 = matr[i+1][j]
        else: cmp1 = '#'
        if j + 1 < m: cmp2 = matr[i][j+1]
        else: cmp2 = '#'
        if cmp1 == cmp2 == '#':
            dp[i][j] = 0
            return 0
        if cmp1 == '#':
            a1 = greedyDFS(i, j+1, n, m, ans+cmp2)
            if not a1:
                dp[i][j] = 0
            else:
                return a1
        elif cmp2 == '#':
            a1 = greedyDFS(i+1, j, n, m, ans+cmp1)
            if not a1:
                dp[i][j] = 0
            else:
                return a1
        elif cmp1 < cmp2:
            a1 = greedyDFS(i+1, j, n, m, ans+cmp1)
            if not a1:
                a2 = greedyDFS(i, j+1, n, m, ans+cmp2)
                if not a2:
                    dp[i][j] = 0
                else:
                    return a2
            else:
                return a1
        elif cmp1 > cmp2:
            a1 = greedyDFS(i, j+1, n, m, ans+cmp2)
            if not a1:
                a2  = greedyDFS(i+1, j, n, m, ans+cmp1)
                if not a2:
                    dp[i][j] = 0
                else:
                    return a2
            else:
                return a1
        else :
            a1 = greedyDFS(i, j+1, n, m, ans+cmp2)
            a2  = greedyDFS(i+1, j, n, m, ans+cmp1)
            if a1 == 0 and a2 == 0:
                dp[i][j] = 0
            elif a1 == 0:
                ans = a2
            elif a2 == 0:
                ans = a1
    return dp[i][j]


for _testcases_ in range(int(input())): 
    n, m = get_ints()
    matr = []
    for i in range(n):
        matr.append(list(input()))
    dp = [[-1] * m for x in range(n)]
    ans = ''
    greedyDFS(0, 0, n, m, ans)
    # print(matr[0][0] + dp[n-1][m-1])


'''
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here, otherwise.
'''
