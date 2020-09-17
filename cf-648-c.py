'''     ##     ##  #######  # #  ######
        ##     ##  ##   ##  ###    ##
        ##     ##  ##    #  # #    ##
        #########  #######  # #    ##    '''

import sys
import math
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())

def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")
def printchk(*args): return print(*args, end=" \ ")

MODPRIME = int(1e9+7); BABYMODPR = 998244353;

from collections import defaultdict
# sys.stdin = open("input.txt","r")  # <<<  Comment this line  >>> #
# for _testcases_ in range(int(input())):
n = int(input())
a = get_list()
b = get_list()
d1 = {}
d2 = {}
for i in range(n):
    d1[a[i]] = i
    d2[b[i]] = i
ans = {}
for i in range(1, n+1):
    val = d1[i] - d2[i]
    if val < 0:
        val += n
    try:
        ans[val] += 1
    except:
        ans[val] = 1
ansmax = 1
for k, v in ans.items():
    if v > ansmax:
        ansmax = v
print(ansmax)
'''
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
TESTCASES:
>>> COMMENT THE STDIN !!
'''