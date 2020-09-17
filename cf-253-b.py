#                           जय श्री राम

import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

# for _testcases_ in range(int(input())):
n = int(input())
li = get_list()
d = Counter(li)
ans = float('inf')
d = sorted(d.items(), key = lambda x:x[0])
n = len(d)
for i in range(n):
    start = d[i][0]
    end = 2 * start
    ind, temp = 0, 0
    while d[ind][0] < start:
        temp += d[ind][1]
        ind += 1
    ind, temp1 = -1, 0
    while d[ind][0] > end:
        temp1 += d[ind][1]
        ind -= 1
    ans = min(ans, temp+temp1)
print(ans)



'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''