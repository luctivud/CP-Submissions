'''     ##     ##  #######  # #  ######
        ##     ##  ##   ##  ###    ##
        ##     ##  ##    #  # #    ##
        #########  #######  # #    ##    '''

import sys
import math
sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())

def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")
def printchk(*args): return print(*args, end=" \ ")

MODPRIME = int(1e9+7); BABYMODPR = 998244353;

ONLINE_JUDGE = 0
if not ONLINE_JUDGE:
    sys.stdin  = open("input.txt","r")
    sys.stdout = open("output.txt","w")
    sys.stderr = open("output.txt","w")

def solve(s, i, n, ans):
    if i != n:
        ans += int(s[i:]) + solve(s, i+1, n, ans)
    return ans
# for _testcases_ in range(int(input())):
s = input()
n = len(s)
ans = solve(s, 0, n, 0)
print(ans)

'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
DO NOT PLAGIARISE.
TESTCASES:
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''