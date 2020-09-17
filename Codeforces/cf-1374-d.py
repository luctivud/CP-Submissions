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
    n, k = get_ints()
    d = Counter(list(map(lambda x: (k-(x%k))%k, get_list())))
    # print(li)
    # print(d)
    se = set()
    if d[0] == n:
        print(0)
    else:
        for key, val in d.items():
            if key == 0:
                continue
            indices = val
            for abc in range(indices):
                while key in se:
                    key += k
                se.add(key)
        # print(se)
        print(max(se)+1)
        


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''