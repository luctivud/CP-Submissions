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


# sys.stdin = open("input.txt","r")  # <<<  Comment this line  >>> #
# for _testcases_ in range(int(input())):
n = int(input())
flag = False; ans = []
for i in range(1, n+1):
    for j in range(1, n+1):
        if (i % j == 0) and (i * j) > n and (i / j) < n:
            ans = [i, j]
            flag = True
            break
    if flag: break
if flag:
    print(" ".join(map(str, ans)))
else:
    print(-1)

'''
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
TESTCASES:
>>> COMMENT THE STDIN !!
'''