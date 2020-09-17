'''     ##     ##  #######  # #  ######
        ##     ##  ##   ##  ###    ##
        ##     ##  ##    #  # #    ##
        #########  #######  # #    ##    '''

import sys
import math
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))

def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")
def printchk(*args): return print(*args, end=" \ ")

MODPRIME = int(1e9+7); BABYMOD = 998244353;

if __name__ == "__main__":
    # sys.stdin = open("input.txt","r")  # <<<  ^o^  Comment this line  ^_^  >>>
    for _testcases_ in range(int(input())):
        n, x = get_ints()
        li = get_array()
        odd, even = 0, 0
        for i in li:
            if i % 2:
                odd += 1
            else:
                even += 1
        rem = x - even
        if rem <= 0:
            if odd:
                print("Yes")
            else:
                print("No")
        elif rem % 2:
            print("Yes")
        else:
            print("No")



# #############################################################################
'''
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
TESTCASES:
'''