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





res = [0, 1, 1, 2]
for i in range(4, 1130):
    thisres = (res[i-1]**2 - pow(-1, i-2)) // (res[i-2])
    res.append(thisres)
print(*enumerate(res))

def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    # print(res)

    a, b = Read_Ints()
    print(math.gcd(res[a], res[b]), res[math.gcd(a, b)], math.gcd(a, b))
    






_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta www
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

