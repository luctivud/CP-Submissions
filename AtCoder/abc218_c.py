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


def checkSame(a, b, offsetX, offsetY, n):
    # for i in a:
    #     print(i)
    # print()
    # for i in b:
    #     print(i)
    for i in range(n):
        for j in range(n):
            if a[(i+offsetX) % n][(j+offsetY)%n] != b[i][j]:
                return False
    return True

def printmat(mat):
    for i in mat:
        print(i)
    print()


def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    n = int(input())
    matr = []
    for i in range(n):
        matr.append(list(input()))
    matrCpy = []
    for i in range(n):
        matrCpy.append(list(input()))
    # print(matr)

    for translateX in range(n):
        for translateY in range(n):
            if checkSame(matr, matrCpy, translateX, translateY, n):
                print("Yes")
                return

    matr = list(zip(*matr[::-1]))   

    for translateX in range(n):
        for translateY in range(n):
            if checkSame(matr, matrCpy, translateX, translateY, n):
                print("Yes")
                return

    matr = list(zip(*matr[::-1]))   
    matr = list(zip(*matr[::-1]))   

    for translateX in range(n):
        for translateY in range(n):
            if checkSame(matr, matrCpy, translateX, translateY, n):
                print("Yes")
                return


    print("No")

    






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta _T0T4
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

