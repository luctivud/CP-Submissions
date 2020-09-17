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


sys.stdin = open("input.txt","r")  # <<<  Comment this line  >>> #
from collections import Counter
for _testcases_ in range(int(input())):
    n = int(input())
    a = get_list()
    b = get_list()
    li = list()
    # d = Counter(a)
    for i in range(n):
        li.append([a[i], b[i]])
    sorted_list = li.copy()
    sorted_list.sort(key = lambda x: x[0])
    flag = True; one = False; zero = False;
    same = diff = 0

    for i in range(n):
        if sorted_list[i][0] != li[i][0]:
            flag = False
        if li[i][1] == 0:
            zero = True
        elif li[i][1] == 1:
            one = True
    if flag:
        print("Yes")
    else:
        if one and zero:
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