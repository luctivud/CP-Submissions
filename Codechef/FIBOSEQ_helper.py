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
from itertools import combinations


def all_subsequences(s):
    out = list()
    for r in range(1, len(s) + 1):
        for c in combinations(s, r):
            out.append(''.join(c))
    return out


def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    n = _TestCase;
    a = "1"; b = "0"
    for i in range(n):
        c = a + b
        b = a
        a = c
    # print(all_subsequences(b))
    print(b)
    print(b.count("1"), b.count("0"))
    # ans = 0
    # for i in all_subsequences(b):
    #     ans += i.count("1")

    # print(ans)

    






_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta d8j
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

