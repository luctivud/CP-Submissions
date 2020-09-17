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

def traverse(matr, dp, i, j, n, m):
    if i < 0 or j < 0 or i >= n or j >= m:
        return
    if dp[i][j] == -1:
        if matr[i][j] == '#':
            dp[i][j] = 0
            return
        else:
            dp[i][j] = 1
            traverse(matr, dp, i+1, j, n, m)
            traverse(matr, dp, i, j+1, n, m)
            traverse(matr, dp, i-1, j, n, m)
            traverse(matr, dp, i, j-1, n, m)
    return dp[i][j]

# sys.stdin = open("input.txt","r")  # <<<  Comment this line  >>> #
for _testcases_ in range(int(input())):
    n, m = get_ints()
    matr = []
    for i in range(n):
        li = list(input())
        matr.append(li)
    flag = True
    for i in range(n):
        for j in range(m):
            if matr[i][j] == 'B':
                if j + 1 < m:
                    if matr[i][j+1] == 'G':
                        flag = False
                    else:
                        matr[i][j+1] = '#'
                if j-1 >= 0:
                    if matr[i][j-1] == 'G':
                        flag = False
                    else:
                        matr[i][j-1] = '#'
                if i + 1 < n:
                    if matr[i+1][j] == 'G':
                        flag = False
                    else:
                        matr[i+1][j] = '#'
                if i - 1 >= 0:
                    if matr[i-1][j] == 'G':
                        flag = False
                    else:
                        matr[i-1][j] = '#'

    if not flag:
        print("No")
    else:
        dp = [[-1] * m for x in range(n)]
        traverse(matr, dp, n-1, m-1, n, m)
        for i in range(n):
            for j in range(m):
                if matr[i][j] == 'G' and dp[i][j] != 1:
                    flag = False
                    break
        if flag:
            print("Yes")
        else:
            print("No")
    


'''
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
TESTCASES:
>>> COMMENT THE STDIN !!
'''