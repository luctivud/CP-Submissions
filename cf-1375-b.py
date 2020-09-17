#                          JAI SHREE RAM

import math; from collections import *
import sys; from functools import reduce

# sys.setrecursionlimit(10**6)
def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def get_string(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e5)

# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")

for _testcases_ in range(int(input())):
    n, m = get_ints()
    matr = []
    for i in range(n):
        matr.append(get_list())
    flag = True
    # if matr[0][0] > 2:
    #     flag = False
    # if matr[0][m-1] > 2:
    #     flag = False
    # if matr[n-1][m-1] > 2:
    #     flag = False
    # if matr[n-1][0] > 2:
    #     flag = False
    queue = deque()
    for i in range(n):
        for j in range(m):
            num = 0
            neighbour = 0
            if j + 1 < m:
                neighbour += 1
                if matr[i][j+1] != 0:
                    num += 1
            if j - 1 >= 0:
                if matr[i][j-1] != 0:
                    num += 1
                neighbour += 1
            if i + 1 < n:
                if matr[i+1][j] != 0:
                    num += 1
                neighbour += 1
            if i - 1 >= 0:
                neighbour += 1
                if matr[i-1][j] != 0:
                    num += 1
            if matr[i][j] > neighbour:
                flag = False
            else:
                need = matr[i][j] - num
                if need < 0:
                    matr[i][j] += need
                elif need > 0:
                    queue.append((i, j, need))
        

    if flag :
        queue = deque()
        while len(queue):
            item = queue.popleft()
            i, j, need = *item
            while need > 0:
                if matr[i][j] != 0:
                    
                need -= 1
        print("YES")
        for i in range(n):
            print(*matr[i])
    else:
        print("NO")

'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''