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
matr = []
for i in range(n):    
    li = list(input())
    matr.append(li)
flag = True
for i in range(n):
    for j in range(n):
        try:
            if matr[i][j] == '.':
                if matr[i+1][j] == matr[i+1][j+1] == matr[i+1][j-1] == matr[i+2][j] == '.':
                    matr[i+1][j] = matr[i+1][j+1] = matr[i+1][j-1] = matr[i+2][j] = '#'
                else:
                    flag = False
                    break
        except:
            flag = False
            break
if flag:
    print("YES")
else:
    print("NO")
'''
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
TESTCASES:
>>> COMMENT THE STDIN !!
'''