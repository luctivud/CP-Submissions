#                           जय श्री राम

import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

MODPRIME = int(1e9+7); BABYMODPR = 998244353; MAXN = int(1e5)

sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

for _testcases_ in range(int(input())):
    s = input()
    m = int(input())
    li = get_list()
    d = Counter(s)
    d = sorted(d.items(), reverse = True)
    # print(d)
    ans = [-1] * m
    temp = m
    while temp:
        se = set()
        for i in range(m):
            if li[i] == 0:
                li[i] = -1
                se.add(i)
        ind = 0
        # print(m, ans, se, li, d)
        while ind < len(d):
            if d[ind][1] >= len(se):
                for j in se:
                    ans[j] = d[ind][0]
                break
            ind += 1
        try:
            d = d[ind+1:]
        except:
            d = []
        for el in se:
            for index in range(m):
                if li[index] != -1:
                    li[index] -= abs(index - el)
        temp -= len(se)

    print(''.join(ans))


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''