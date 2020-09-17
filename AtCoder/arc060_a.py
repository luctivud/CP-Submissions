'''     ##     ##  #######  # #  ######
        ##     ##  ##   ##  ###    ##
        ##     ##  ##    #  # #    ##
        #########  #######  # #    ##    '''
# incomplete

import sys
import math
sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())

def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")
def printchk(*args): return print(*args, end=" \ ")

MODPRIME = int(1e9+7); BABYMODPR = 998244353;


ONLINE_JUDGE = 1
if not ONLINE_JUDGE:
    sys.stdin  = open("input.txt","r")
    sys.stdout = open("output.txt","w")
    sys.stderr = open("output.txt","w")

def solve(li, dp, i, n, delta, a):
    if i == n:
        if delta == a:
            return 1
        else:
            return 0
    if dp[i][delta] == -1:
        dp[i][delta] = 0
        dp[i][delta] += solve(li, dp, i+1, n, delta, a)
        pass
    return dp[i][delta]

# for _testcases_ in range(int(input())):
n, a = get_ints()
li = get_list()
dp = [[-1] * 5001 for i in range(n)]
solve(li, dp, 0, n, 0, a)

'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
DO NOT PLAGIARISE.
TESTCASES:
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''