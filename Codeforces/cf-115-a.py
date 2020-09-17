#                          JAI SHREE RAM

import math; from collections import *
import sys; from functools import reduce

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def getlistofstring(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e5)

# sys.setrecursionlimit(10**6)
# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")

# for _testcases_ in range(int(input())):
N = int(input())
manager = defaultdict(list)
queue = deque()
depth = [0] * (N+1)
for sub in range(1, N+1):
    man = int(input())
    if man == -1:
        queue.append([sub, 1])
        depth[sub] = 1
    else:
        manager[man].append(sub)
# print(queue)
# print(manager)
while len(queue):
    # print(queue)
    this = queue.popleft()
    man = this[0]
    dep = this[1] + 1
    for sub in manager[man]:
        if depth[sub] != dep:
            queue.append([sub, dep])
            depth[sub] = dep
print(max(depth))
        






'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''