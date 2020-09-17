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

for _testcases_ in range(int(input())):
    n, a, b = input().split()
    d = defaultdict(list)
    visited = set()
    queue = deque()
    for i in range(int(n)):
        x, y = input().split()
        d[x].append(y)
        d[y].append(x)
    queue.append(a)
    flag = False
    while len(queue):
        thisboy = queue.popleft()
        found = True
        while thisboy in visited:
            try:
                thisboy = queue.popleft()
            except:
                found = False
                break
        if not found: break
        visited.add(thisboy)
        for boy in d[thisboy]:
            if boy not in visited:
                queue.append(boy)
                if boy == b:
                    flag = True
                    break
        # print(queue)
    if flag:
        print('Quarantine')
    else:
        print('Stay Home, Stay Safe')



'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''