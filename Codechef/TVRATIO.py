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
    a, b, x, y = Read_Ints()
    l = 0; r = (a * b) // (x * y); fac = 0;

    while (l <= r) :
        mid = (l + r) // 2;
        if ((x * y * mid * mid) <= (a * b) and x*mid <= a and y*mid <= b):
            fac = mid;
            l = mid + 1;
        else:
            r = mid - 1;

    
    print(fac * x, fac * y);





_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta d8j
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

