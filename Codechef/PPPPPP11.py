#                 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/                     #


import math;           from collections import *
import sys;           from functools import reduce
import time;           from itertools import groupby
import heapq

# sys.setrecursionlimit(10**6)

# def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (+1, -1)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]



# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

# for _test_ in range(int(input())): 
N = int(input())
events = []
for i in range(N):
    events.append(get_list())
if N <= 1: 
    print(1)
else:
    events.sort(key = lambda x: x[0])
    start, end = float('inf'), -float('inf')
    for s, e in events:
        start = min(start, s)
        end = max(end, e)

    nevents, i = 0, 0
    h = []

    for day in range(start, end+1):
        while i < N and events[i][0] == day:
            heapq.heappush(h, events[i][1])
            i += 1
        while h and h[0] < day:
            heapq.heappop(h)
        if h:
            heapq.heappop(h)
            nevents += 1

    print(nevents)





