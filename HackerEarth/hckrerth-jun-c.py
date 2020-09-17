#                           जय श्री राम

import sys; import math; from collections import *
from functools import reduce
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

#sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

# for _testcases_ in range(int(input())):
n, m = get_ints()
matr = []
for i in range(n):
    matr.append(list(input()))

ans = [[1]*m for x in range(n)]

def solve(matr, i, j, n, m, ans):
    if i == n or j == m:
        return 1
    if matr[i][j] == '#':
        return 1
    if i == n-1 and j == m-1:
        ans[i][j] = 0
    if ans[i][j] == 1:
        ans[i][j] = min(solve(matr, i+1, j, n, m, ans), solve(matr, i, j+1, n, m, ans))
    return ans[i][j]


def checkdp(ans, i, j, n, m):
    if i == n or j == m:
        return
    if ans[i][j] == 1:
        return
    if i+1 < n and j+1 < m:
        if ans[i+1][j] == 0 and ans[i][j+1] == 0:
            brkpnt.append([i, j])
            return
    checkdp(ans, i+1, j, n, m)
    checkdp(ans, i, j+1, n, m)    
    return

def checkrev(ans, i, j):
    if i < 0 or j < 0 :
        return
    if ans[i][j] == 1:
        return
    if i-1 >= 0 and j-1 >= 0:
        if ans[i-1][j] == 0 and ans[i][j-1] == 0:
            brkpnt.append([i, j])
            return
    checkrev(ans, i-1, j)
    checkrev(ans, i, j-1)
    return


solve(matr, 0, 0, n, m, ans)
    
brkpnt = []
checkdp(ans, 0, 0, n, m)
checkrev(ans, n-1, m-1)
# print(brkpnt)
try:
    start = brkpnt[0]
except:
    start = [0, 0]
try:
    end = brkpnt[1]
except:
    end = [n-1, m-1]
start[0] = max(0, start[0])
end[0] = min(end[0], n-1)
start[1] = max(0, start[1])
end[1] = min(end[1], m-1)

for i in range(start[0], end[0]+1):
    for j in range(start[1], end[1]+1):
        if [i, j] not in brkpnt:
            ans[i][j] = 1


for i in ans:
    for j in i :
        printsp(j)
    print()


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''