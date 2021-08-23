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
    a, b, c  = Read_Ints()
    diff = abs(b - a)

    maxNum = 2 * diff

    if (a > maxNum or b > maxNum):
        print(-1)
        return

    # print(maxNum, "mx");
    # print(c+diff, "c")
    se = set([a, b])

    if (((c + diff) not in se) and ((c + diff) <= maxNum)) and ((c + diff) > 0):
        print(c + diff)
    elif (((c - diff) not in se) and (c - diff <= maxNum) and ((c - diff) > 0)):
        print(c - diff)
    else:
        print(-1)






_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta d8j
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

