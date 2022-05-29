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
    n = int(input())
    nstr = str(n)
    nsz = len(nstr)
    ans = int('9' * (nsz - 1))
    for i in range(1, nsz//2+1):
        repNum = nstr[:i]
        times = nsz // len(repNum)
        newNum = int(repNum * times)
        while newNum > n:
            repNum = str(int(repNum) - 1)
            times = nsz // len(repNum)
            newNum = int(repNum * times)
        # print(newNum)
        ans = max(ans, newNum)
    print(ans)






_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

