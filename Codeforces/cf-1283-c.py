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

n = int(input())
li = list(map(lambda x: x-1, get_list()))
selfloops = []
indegree = [0] * n
outdegree = [0] * n
for i, v in enumerate(li):
    if v != -1:
        outdegree[i] = 1
        indegree[v] = 1
# print(indegree, outdegree)

for i in range(n):
    if not (indegree[i] | outdegree[i]):
        selfloops.append(i)
if len(selfloops) == 1:
    for i in selfloops:
        for j in range(n):
            if indegree[j] == 0 and i!=j:
                indegree[j] = 1
                outdegree[i] = 1
                li[i] = j
                break
elif len(selfloops) > 1:
    sz = len(selfloops)
    for i in range(sz):
        v1 = selfloops[i]
        v2 = selfloops[(i+1)%sz]
        li[v1] = v2
        outdegree[v1] = 1
        indegree[v2] = 1

remainIns = [i for i in range(n) if indegree[i]==0]
remainOuts = [i for i in range(n) if outdegree[i] == 0]

sz = len(remainIns)

for i in range(sz):
    v1 = remainIns[i]
    v2 = remainOuts[i]
    li[v2] = v1

print(*list(map(lambda x: x+1, li)))




'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''