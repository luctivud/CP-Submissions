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


def isPrime(num):
    for i in range(2, num):
        if num % i == 0:
            return False

    return True




def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    d = collections.defaultdict(int)
    a, b = Read_Ints()
    for i in range(a, b+1):
        for j in range(i, b+1):
            num = ((j*(j+1)) - (i * (i -1))) // 2
            if (isPrime(num)):
                print(i, j)
                d[i] += 1
                d[j] += 1

    # print(*d.items(), sep = "\n")
    






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta d8j
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

