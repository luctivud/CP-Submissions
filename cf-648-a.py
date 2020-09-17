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
for _testcases_ in range(int(input())):
    n, m = get_ints()
    matr = []
    for i in range(n):
        li = get_list()
        matr.append(li)
    unclaimed_rows, unclaimed_cols = set([i for i in range(n)]), set([x for x in range(m)])
    for i in range(n):
        for j in range(m):
            if matr[i][j] == 1:
                try:
                    unclaimed_cols.remove(j)
                except:
                    pass
                try:
                    unclaimed_rows.remove(i)
                except:
                    pass
    ans = min(len(unclaimed_cols), len(unclaimed_rows))
    # print(unclaimed_cols, unclaimed_rows, ans)
    if ans & 1:
        print("Ashish")
    else:
        print("Vivek")

'''
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
TESTCASES:
>>> COMMENT THE STDIN !!
'''