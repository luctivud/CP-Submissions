#                           जय श्री राम

import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

MODPRIME = int(1e9+7); BABYMODPR = 998244353; MAXN = int(1e5)

# sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

for _testcases_ in range(int(input())):
    n, k = get_ints()
    s = input()
    li = []
    for i, v in enumerate(s):
        if v == '1':
            li.append(i)
    prev = -float('inf')
    try:
        nxt = li[0]
    except:
        nxt = float('inf')
    i = j = ans = 0
    # print(li)
    while i < n:
        if i - prev > k and nxt - i > k:
            ans += 1
            prev = i
        if i >= nxt:
            prev = nxt
            j += 1
            try:
                nxt = li[j]
            except:
                nxt = float('inf')
        # print(prev, nxt, i, ans)
        i += 1
    print(ans)


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''