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
#########################################################################
MOD = int(1e9+7); BABYMOD = 998244353;
import random
for _testcases_ in range(int(input())):
    n, m, k = get_ints()
    matrix = []
    for i in range(n):
        li = get_array()
        matrix.append(li)
    # print(matrix)
    ansli = [-1]*n
    countOfK = {}
    lower_bound = mt.ceil(n/k)
    freqDict = [[[]*n for x in range(m)] for y in range(k)]
    # print(freqDict)
    for i in range(n):
        for j in range(k):
            # print(matrix[i][j])
            try:
                freqDict[i][matrix[i][j]-1].append(i)
            except: pass
        maxcount = 0; se= set(); mind = -1
        # print(freqDict)
        for key, v in freqDict.items():
            if len(v)>maxcount:
                mind = key
                maxcount = len(v)
                se = set(v)
        ansli[i] = mind
    # # print(freqDict)
    for i in range(n):
        printsp(matrix[i][random.randint(0,k-1)])
    print()
            # print(mind)
        #     try:
        #         countOfK[mind].add(se)
        #     except:
        #         countOfK[mind] = set(se)
        # lessThanLower=[]; moreThanLower=[]
        # print(countOfK)
        # for ks in range(k):
        #     kcount = len(countOfK[ks])
        #     if kcount<lower_bound:
        #         lessThanLower.append(ks)
        #     elif kcount> lower_bound:
        #         moreThanLower.append(ks)
        # # print(lessThanLower, moreThanLower)
        # print(ansli)

'''
THE LOGIC AND APPROACH WAS DEVELOPED BY ME @luctivud.
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
PLEASE DO NOT PLAGIARISE.
1
4 2 2
1 2
2 1
1 1
2 2
'''