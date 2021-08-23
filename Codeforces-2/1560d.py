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

pow2 = [1]

# def binsy(num):
#     l = 0; r = 32; ans = 0
#     while l <= r:
#         mid = (l + r) // 2
#         if (pow2[mid] >= num):
#             ans = mid
#             r = mid - 1
#         else:
#             l = mid + 1
#     return pow2[ans]


def checkFor(num):
    if num == '':
        return float('inf')
    num = num[::-1]
    # print(num)
    sz = len(num)
    z = binsy(int(num))
    return sz - len(str(z)) + (z - int(num))


def solve(num, ind, res, cnt):
    if (ind == len(num)):
        return cnt + checkFor(res)
    return min(solve(num, ind+1, res, cnt+1), solve(num, ind+1, res+num[ind], cnt))


from itertools import combinations

def all_subsequences(s):
    if ind == len
    # out = []
    # for r in range(1, len(s) + 1):
    #     for c in combinations(s, r):
    #         out.append(''.join(c))
    # return out


def gac(num):
    if (num == ''):
        return 1
    res = float('inf')
    for i in range(64):
        if (len(pow2[i]) < len(num)):
            continue
        if (pow2[i][:len(num)] == num):
            res = min(res, len(pow2[i]) - len(num))
    # print(num, res)
    return res


def huehuehue(num):
    return len(num) - len(num.lstrip('0')) + gac(num.lstrip('0'))

def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    n = input()
    # print(solve(n, 0, '', 0))
    subs = all_subsequences(n)
    ans = float('inf')
    subs.append('')
    # print(subs)
    for i in subs:
        ans = min(ans, len(n) - len(i) + huehuehue(i))

    print(ans)

    






_T0T4 = 1;
_T0T4 = int(input()) 
    

for i in range(64):
    pow2.append(pow2[-1] * 2)

for i in range(64):
    pow2[i] = str(pow2[i])

# print(pow2)

for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta d8j
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

