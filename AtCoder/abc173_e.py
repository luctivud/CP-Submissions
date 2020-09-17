#                          JAI SHREE RAM

import math; from collections import *
import sys; from functools import reduce

# sys.setrecursionlimit(10**6)
def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def get_string(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e5)

# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")

# for _testcases_ in range(int(input())):
n, k = get_ints()
li = get_list()
pos = []
neg = []
ans = 1
zeroes = 0
for i in li:
    if i < 0: neg.append(i)
    elif i > 0: pos.append(i)
    else: zeroes += 1
lengthOfPos, lengthOfNeg = len(pos), len(neg)

if k&1 : #and (k - lengthOfPos) >= 0 and (k - lengthOfPos) & 1:
    if k > lengthOfPos:
        if zeroes:
            print("0")
        else:
            # last pr pakka negative ayega
            pos.extend([0] * zeroes)
            lengthOfPos, lengthOfNeg = len(pos), len(neg)
            pos.sort(); positionOfPos = 0
            neg.sort(reverse = True); positionOfNeg = 0
            while k > 1:
                try: negpower = neg[positionOfNeg] * neg[positionOfNeg+1]
                except: negpower = float('inf')
                try: pospower = pos[positionOfPos] * pos[positionOfPos+1]
                except: pospower = float('inf')
                if pospower <= negpower:
                    positionOfPos += 2
                    ans = (ans * (pospower % UGLYMOD)) % UGLYMOD
                else:
                    ans = (ans * (negpower % UGLYMOD)) % UGLYMOD
                    positionOfNeg += 2
                k -= 2
            if k == 1:
                try: negpower = neg[positionOfNeg]
                except: negpower = float('inf')
                try: pospower = pos[positionOfPos]
                except: pospower = float('inf')
                ans = (ans * min(pospower, negpower)) % UGLYMOD
            print(ans)
            
    else:
        pos.sort(reverse = True); positionOfPos = 0
        neg.sort(); positionOfNeg = 0
        ans = 1
        while k > 1:
            try: negpower = neg[positionOfNeg] * neg[positionOfNeg+1]
            except: negpower = -float('inf')
            try: pospower = pos[positionOfPos] * pos[positionOfPos+1]
            except: pospower = -float('inf')
            if pospower >= negpower:
                positionOfPos += 2
                ans = (ans * (pospower % UGLYMOD)) % UGLYMOD
            else:
                ans = (ans * (negpower % UGLYMOD)) % UGLYMOD
                positionOfNeg += 2
            k -= 2
        if k == 1:
            ans = (ans * pos[positionOfPos]) % UGLYMOD
        print(ans)
else:
    pos.sort(reverse = True); positionOfPos = 0
    neg.sort(); positionOfNeg = 0
    ans = 1
    while k > 1:
        try: negpower = neg[positionOfNeg] * neg[positionOfNeg+1]
        except: negpower = -float('inf')
        try: pospower = pos[positionOfPos] * pos[positionOfPos+1]
        except: pospower = -float('inf')
        if pospower >= negpower:
            positionOfPos += 2
            ans = (ans * (pospower % UGLYMOD)) % UGLYMOD
        else:
            ans = (ans * (negpower % UGLYMOD)) % UGLYMOD
            positionOfNeg += 2
        k -= 2
    if k == 1:
        ans = (ans * pos[positionOfPos]) % UGLYMOD
    print(ans)







'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''