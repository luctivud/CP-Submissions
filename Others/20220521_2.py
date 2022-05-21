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
    PRECISION = 4
    X = Read_Array()
    Y = Read_Array()
    n = len(X)
    Mx = round(sum(X) / n, PRECISION)
    My = round(sum(Y) / n, PRECISION)
    table = []
    sumxy = sumx2 = sumy2 = 0
    table.append(["X", "Y", "x", "y", "x*y", "x2", "y2"])
    for i in range(n):
        x = X[i] - Mx
        y = Y[i] - My
        xy = x * y
        x2 = x * x
        y2 = y * y
        res = [X[i], Y[i], x, y, xy, x2, y2]
        sumxy += xy
        sumx2 += x2
        sumy2 += y2
        res2 = []
        for j in res:
            res2.append(round(j, PRECISION))
        table.append(res2)
        
    table.append(["", "", "", "", round(sumxy, PRECISION), round(sumx2, PRECISION), round(sumy2, PRECISION)])
    for i in table:
        s = " ".join([str(j).ljust(10) for j in i])
        print(s)





_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

