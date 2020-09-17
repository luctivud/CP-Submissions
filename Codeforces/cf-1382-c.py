'''     ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█  
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     '''


# [cf-1382-c.py] => [21-07-2020 @ 20:28:34] 
# Author & Template by : Udit "luctivud" Gupta
# https://www.linkedin.com/in/udit-gupta-1b7863135/


import math;   from collections import *
import sys;    from functools import reduce
import time;   from itertools import groupby

# sys.setrecursionlimit(10**6)

def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (+1, -1)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]


CAPS_ALPHABETS = {chr(i+ord('A')) : i for i in range(26)}
SMOL_ALPHABETS = {chr(i+ord('a')) : i for i in range(26)}
INF = float('inf')


# Custom input output is now piped through terminal commands.


S34t = time.time()
for _testcases_ in range(int(input())): 
    n = int(input())
    a = list()
    b = list()
    temp = input()
    for i in range(n):
        a.append(int(temp[i]))
    temp = input()
    for i in range(n):
        b.append(int(temp[i]))
    # a = list(map(int, list(input())))
    # b = list(map(int, list(input())))
    # print(a, b)
    j = n-1; i = 0
    first = second = 0
    last = n-1
    ans = []
    while last >= 0:
        if second & 1:
            # i
            if a[last] != b[last]:
                if a[i] == b[last]:
                    first += 1
                    ans.append(1)
                ans.append(last+1)
                second += 1
            i += 1
        else:
            # j
            if a[last] == b[last]:
                if a[j] != b[last]:
                    first += 1
                    ans.append(1)
                ans.append(last+1)
                second += 1
            j -= 1
        last -= 1
    print(first + second, *ans)




S34p = time.time()
# print("Time Elapsed: {}".format(float(S34p-S34t)))
''' ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                             SHREE RAM JAI RAM, JAI JAI RAM 
                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'''
