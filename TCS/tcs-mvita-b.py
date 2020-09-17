
import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")
def seive():
    prime = [True] * (MAXN+1)
    prime[0] = prime[1] = False
    i = 2
    while i*i <= MAXN:
        if prime[i] == True :
            for j in range(i*2, MAXN+1, i):
                prime[j] = False
        i += 1
    return prime

# for _testcases_ in range(int(input())):
prime = seive()
# print(prime[:40])
l, r = get_ints()
li = []
for i in range(l, r):
    if prime[i]:
        li.append(i)
n = len(li)
# print(li)
se = set()
for i in range(n):
    for j in range(n):
        if i != j:
            this = int(str(li[i])+str(li[j]))
            if prime[this]:
                se.add(this)
# print(se)
mn, mx, sz = min(se), max(se), len(se)
# print(mn, mx)
for i in range(sz-1):
    mn, mx = mx, mn+mx
print(mn)


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''