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





def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    ans = float('inf')
    n = int(input())
    s = input()
    md1 = n // 2
    md2 = md1 - 1

    while (md2 > 0 and s[md2] == 0):
        md2 -= 1
    while (md1 < n and s[md1] == 0):
        md1 += 1

    md1 += 1
    md2 += 1

    print(md1, md2)
    print(int(s[:md1]), int(s[md1:]))
    print(int(s[:md2]), int(s[md2:]))
    ans = min(ans, int(s[:md1]) + int(s[md1:]))
    if (md2 <= n):
        ans = min(ans, int(s[:md2]) + int(s[md2:]))
    
    print(ans)





_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta time
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

