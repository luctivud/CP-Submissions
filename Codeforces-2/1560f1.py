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
    n, K = Read_Ints()
    n = str(n)
    if (K == 1):
        ans = int('1' * (len(n)+1))
        for i in range(1, 10):
            riza = str(i) * len(n)
            if int(riza) >= int(n):
                ans = min(ans, int(riza))
        print(ans)
    else:
        ans = int('1' +  '0' * (len(n)))
        for i in range(0, 10):
            for j in range(i, 10):
                num = list(n)
                done = False
                for k in range(len(n)):
                    if done:
                        num[k] = str(i);
                        continue
                    if num[k] < str(i):
                        done = True
                        num[k] = str(i)
                    elif num[k] > str(i) and num[k] < str(j):
                        done = True
                        num[k] = str(j)
                # print(i, j, num)
                num = "".join(num)
                if len(set(num)) <= K and int(num) >= int(n):
                    ans = min(ans, int(num))
        print(ans)







_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta d8j
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

