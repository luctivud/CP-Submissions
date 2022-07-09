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


def check(a):
    for i in a:
        if i > 1:
            return False
    return True


def pureString(s):
    n = len(s)
    dp = [[0 for x in range(26)] for y in range(n)]
    for i in range(n-1, -1, -1):
        ch = ord(s[i]) - ord('a')
        dp[i][ch] += 1
        if i+1 < n:
            for j in range(26):
                dp[i][j] += dp[i+1][j]
    curr = [0 for x in range(26)]
    for i in dp:
        print(i)
    res = 0
    for i, v in enumerate(s):
        ch = ord(v) - ord('a')
        curr[ch] += 1
        l, r, ans = i+1, n-1, n
        while l <= r:
            mid = (l + r) // 2
            ok = True
            for j in range(26):
                curr[j] += dp[mid][j]
            ok = check(curr)
            for j in range(26):
                curr[j] -= dp[mid][j]
            print(ok, mid)
            if ok :
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        if (ans != n):
            res += (ans + check(curr))

    return res


def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    
    s = input()

    print(pureString(s))




_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

