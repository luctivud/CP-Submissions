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

def findMid(l, r):
    k = r - l + 1
    if k & 1:
        return [(l+r)//2]
    return [l + k//2 - 1, l + k//2]



def findAns(arr, k):
    arr.sort()
    ans = float('inf')
    n = len(arr)
    presum = [0 for x in range(n+1)]
    for i in range(n):
        presum[i+1] = presum[i] + arr[i]
    # print(arr)
    # print(presum)
    for i in range(n-k+1):
        l, r = i, i+k-1
        mids  = findMid(l, r)
        # print(mids, l, r)
        for mid in mids:
            res =  (arr[mid] * (mid - l +1)) - presum[mid+1] + presum[l]
            res +=  - (arr[mid] * (r - mid)) + presum[r+1] - presum[mid+1]
            ans = min(ans, res)
    return ans


def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    n = int(input())
    arr = Read_Array()
    k = int(input())
    print(findAns(arr, k))






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

