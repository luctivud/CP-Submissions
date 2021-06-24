#   J A I  S H R E E  R A M   #


import math, sys, collections, functools, time, itertools;

sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

mod = int(1e9) + 7


def gcdd(a, b):
    if a == 0:
        return b
    return gcdd(b % a, a)



def multiply(a, b):
    mul = [[0 for x in range(3)] for y in range(3)];
    for i in range(3):
        for j in range(3):
            mul[i][j] = 0;
            for k in range(3):
                mul[i][j] += (a[i][k] * b[k][j]) % mod;
    for i in range(3):
        for j in range(3):
            a[i][j] = mul[i][j]; # Updating our matrix
    return a;
 
def power(F, n):
    M = [[1, 1, 1], [1, 0, 0], [0, 1, 0]];
    if (n == 1):
        return (F[0][0] + F[0][1]) % mod;
 
    power(F, int(n // 2));
    F = multiply(F, F);
    if (n % 2 != 0):
        F = multiply(F, M);
    return (F[0][0] + F[0][1]) % mod ;
 

def findNthTerm(n):
    F = [[1, 1, 1], [1, 0, 0], [0, 1, 0]];
    if n == 0: return 0
    if n == 1: return 1
    if n == 2: return 1
    return power(F, n - 2);


def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    a, b = Read_Ints()
    # a = int(input())
    # b = int(input())
    G = gcdd(b, a)
    # print(G);
    print(findNthTerm(G))
    


_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta www
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

