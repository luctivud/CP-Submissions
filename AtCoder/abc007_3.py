#                           जय श्री राम

import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(50)

sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

def solve(matr, dp, x1, y1, x2, y2, n, m, moves):
    print(x1, y1, moves)
    if x1 >= n or y1 >= m:
        return float('inf')
    if x1 == n and x2 == m:
        return moves
    if matr[x1][y1] == '#':
        dp[x1][y1] = float('inf')
        return dp[x1][y1]
    if dp[x1][y1] == None:
        # dp[x1][y1] = float('inf')
        dp[x1][y1] = min(solve(matr, dp, x1+1, y1, x2, y2, n, m, moves+1), solve(matr, dp, x1-1, y1, x2, y2, n, m, moves+1), solve(matr, dp, x1, y1+1, x2, y2, n, m, moves+1), solve(matr, dp, x1, y1-1, x2, y2, n, m, moves+1))
    return dp[x1][y1]

# for _testcases_ in range(int(input())):
n, m = get_ints()
x1, y1 = get_ints()
x2, y2 = get_ints()
matr = []
for i in range(n):
    li = list(input())
    matr.append(li)
dp = [[None]*m for x in range(n)]
print(solve(matr, dp, x1-1, y1-1, x2-1, y2-1, n, m, 0), dp)



'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''