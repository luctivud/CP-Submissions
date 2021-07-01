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
s = 0
ans = []

def findans(arr, a, b, res):
    # print(arr, a, b, res)
    if (res == 3): return
    if (a == 0) or (b == 0):
        # print(res)
        global ans;
        ans.append((res, 'a' if a == 0 else 'b'))
        return
    for i in range(s):
        if arr[i] == 1:
            a -= 1
            b += 1
            arr[i] ^= 1
            findans(arr, a, b, res+1)
            a += 1
            b -= 1
            arr[i] ^= 1
        else:
            b -= 1
            a += 1
            arr[i] ^= 1
            findans(arr, a, b, res+1)
            b += 1
            a -= 1
            arr[i] ^= 1





def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase))     
    a, b = Read_Ints()
    global s;
    s = a + b 
    arr = []
    for i in range(a):
        arr.append(1)
    for i in range(b):
        arr.append(0)

    findans(arr, a, b, 0)
    global ans;
    print(sorted(collections.Counter(ans).items()))
    ans1 = ans2 = 0
    for ke, va in collections.Counter(ans).items():
        ans1 += va * ke[0]
        ans2 += va
    print(ans1 / ans2)







_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta https
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

