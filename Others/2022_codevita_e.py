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

inf = float('inf')



def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    m1 = int(input())
    m2 = int(input())
    n = int(input())
    li = Read_Array()
    dp = [[0, 0] for x in range(n+1)]

    for i in range(n):
        dp[i+1][0] = min(dp[i][0] + m1 * li[i], dp[i][1] + m1 * li[i])
        dp[i+1][1] = min(dp[i][0] + m2 * li[i], dp[i][1] + m2 * li[i])

    for i in dp:
        print(i)




_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

