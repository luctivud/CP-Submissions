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
    matr = []
    for i in range(n):
        matr.append(Read_Array())
        
    # print(matr)

    s = input()
    netRotate = 0
    for i in s:
        if (i == 'R'):
            netRotate += 1
        else:
            netRotate -= 1
    netRotate += 4
    netRotate %= 4

    for i in range(netRotate):
        matr = list(zip(*matr[::-1]))

    for i in matr:
        print(*i)






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta _T0T4
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

