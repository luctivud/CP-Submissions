import sys; import math; from collections import *
sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

# sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

# for _testcases_ in range(int(input())):
n = int(input())
matr = []
for i in range(n):
    li = get_list()
    matr.append(li)
# print(matr)
dp = [[float('inf')]*n for i in range(n)]
def solve(matr, dp, i, j, n, curr):
    # printsp(i, j, curr, ",")
    if i >= n or j >= n:
        return float('inf')
    if i == n-1 and j == n-1:
        dp[i][j] = min(curr//2 + matr[i][j], dp[i][j])
    if dp[i][j] > curr//2 + matr[i][j]:
        curr = curr//2 + matr[i][j]
        dp[i][j] = min(dp[i][j], solve(matr, dp, i+1, j, n, curr), solve(matr, dp, i, j+1, n, curr))
    return dp[i][j]
print(solve(matr, dp, 0, 0, n, 0))
# for i in dp:
#     print(i)


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''