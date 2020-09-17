#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#   '          .       ,     神 | 光      .     '        .      , #
#     .      '        Udit Gupta @luctivud         ,              #
#  ,    '   ELDIOS | LIGHT | GREED | CIPHER | XAYN | KIRA '    .  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
                ##     ##   ######   # #  ######
                ##     ##   ##  ##   ###    ##
                ##     ##   ##   #   # #    ##
                ###### ##   ######   # #    ##
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~| WORSHIPPER OF GREED |~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
import sys
import math as mt
# sys.setrecursionlimit(10**6)
def printsp(*args): return print(*args, end=" ")
def printchk(*args): return print(*args, end="tst, ")
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()
MOD = int(1e9+7); BABYMOD = 998244353;
#########################################################################
dp = [0]*1000
# def getsquareroot():
#     for i in range(1,999):
#         dp[i] = i + dp[i-1]
# seive()
for _testcases_ in range(int(input())):
    n=int(input())
    ans = 0
    cuberoot = int(n**(1./3.))
    squareroot = int(n**(1./2.))
    alreadyComputed = set()
    for i in range(2, cuberoot):
        if i not in alreadyComputed:
            divi = i
            while(True):
                divi *= i
                alreadyComputed.add(divi)
                quot = n//divi
                ans+= (quot * divi) % MOD
                ans = ans % MOD
                if quot <=1:
                    break
    for i in range(cuberoot, squareroot+1):
        if i not in alreadyComputed:
            divi = i
            while(True):
                divi *= i
                alreadyComputed.add(divi)
                quot = n//divi
                ans+= (quot * divi) % MOD
                ans = ans % MOD
                if quot <=1:
                    break
    if n==1:ans=0
    print((ans+n) % MOD)
'''
THE LOGIC AND APPROACH WAS DEVELOPED BY ME @luctivud.
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
PLEASE DO NOT PLAGIARISE.
10
12
190
36
144
34
565
1454
23
1
12
    corect ans  
41
2855
292
2177
241
15408
62667
93
1
41
'''