#                          JAI SHREE RAM

import math; from collections import *
import sys; from functools import reduce

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def getlistofstring(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e5)

sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")
n, m, k = get_ints()
a = deque(get_list())
b = deque(get_list())
ans = i = j = 0
while True:
    try:
        a1 = a[0]
    except:
        a1 = float('inf')
    try:
        b1 = b[0]
    except:
        b1 = float('inf')
    if a1 < b1:
        if k - a1 >= 0:
            k -= a1
            ans += 1
            a.popleft()
        else:
            break
    else:
        if k - b1 >= 0:
            k -= b1
            ans += 1
            b.popleft()
        else:
            break
    print(a, b)
print(ans)





# sys.setrecursionlimit(10**6)

# for _testcases_ in range(int(input())):

'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''