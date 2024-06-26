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
    x, y, a, b = Read_Ints()
    beta_01 = (x * b - y * a);
    beta_02 = (b * b - a * a);

    if (a == b) :
        zeke = (min(x, y) // a);
        print(zeke);
        return;

    beta = 0;
    l = 0; r = int(1e9);

    while (l <= r):
        mid = (l+r) // 2;
        if (mid * beta_02 <= beta_01):
            beta = mid;
            l = mid + 1;
        else:
            r = mid - 1;
    alpha = (x - (beta * b)) // a;
    alpha = min(alpha, (y - (beta * a)) // b);
    print(alpha, beta);
    print(alpha + beta);    






_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

