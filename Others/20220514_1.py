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

def findAns(s):
    n = len(s)
    l, r, ans = 0, n, n
    cnt = [[0 for x in range(26)] for y in range(n+1)]
    for i in range(n):
        for j in range(26):
            cnt[i+1][j] = cnt[i][j] + (j == (ord(s[i]) - ord('a')))
    # print(cnt)
    while l <= r:
        k = (l + r) // 2
        possible = False
        cnt2 = [0] * 26
        for i in range(n-k+1):
            start, end = i, i+k-1
            for j in range(26):
                cnt2[j] = 
        if possible:
            r = k - 1
            ans = k
        else:
            l = k + 1
    return ans




def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    s = input()
    print(findAns(s))
    






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
