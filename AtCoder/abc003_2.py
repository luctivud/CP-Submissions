#                           जय श्री राम

import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

MODPRIME = int(1e9+7); BABYMODPR = 998244353; MAXN = int(1e5)

# sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

# for _testcases_ in range(int(input())):
s = input()
t = input()
flag = True
for i in range(min(len(s), len(t))):
    if s[i] == t[i]:
        continue
    elif s[i] == '@' or t[i] == '@':
        if s[i] == '@':
            if t[i] not in 'atcoder':
                flag = False
                break
        else:
            if s[i] not in 'atcoder':
                flag = False
                break
    else:
        flag = False
        break
if len(s) != len(t):
    flag = False
print("You can win") if flag else print("You will lose")

        


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''