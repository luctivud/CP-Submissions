#   J A I  S H R E E  R A M   #


import math, sys, collections, functools, time, itertools;

# sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


dp = [[0 for x in range(4)] for y in range(4)]
def getDP(i, j):
    if i < 0:
        return 0
    if j < 0 or j > 3:
        return float('inf')
    return dp[i][j]

def findAns(matr):
    for i in range(4):
        for j in range(4):
            dp[i][j] = matr[i][j] + min(getDP(i-1, j), getDP(i-1, j-1), getDP(i-1, j+1))
    return max(0, 100 - min(dp[3]))



def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    n = int(input())
    m = int(input())
    matr = []
    for i in range(n):
        matr.append(Read_Array())
    print(findAns(matr))






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

