#   J A I  S H R E E  R A M   #


import math, sys, collections, functools, time, itertools;
import collections
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
    adj = [[] for x in range(n+1)]
    for i in range(1, n+1):
        adj[i] = list(map(int, input().split()))
    start, end = map(int, input().split())
    visited = [False for x in range(n+1)]
    ans = -1
    queue = collections.deque()
    queue.append((start, 0))
    visited[start] = True
    while queue:
        node, degree = queue.popleft()
        if node == end:
            ans = degree
            break
        for i in adj[node]:
            if not visited[i]:
                visited[i] = True
                queue.append((i, degree+1))

    print(ans)






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

