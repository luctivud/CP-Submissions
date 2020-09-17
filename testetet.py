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
def getExpo(n):
    if n%4==0:  return 2
    elif n%2==0: return 1
    return 0
for _testcases_ in range(int(input())):
    n = int(input())
    li = get_array()
    expArr=[]
    checkPoints = [[-1,-1] for x in range(n)]
    for i in li:
        expArr.append(getExpo(i))
    last0=-1; last1=-1;
    for i in range(n):
        if expArr[i]==0 and last0==-1: last0=i
        elif expArr==1:
            if last0 != -1 :
                checkPoints[last0][0] = last0
                checkPoints[last0][1] = i
                last0 = -1
            if last1 != -1:
                checkPoints[last1][0] = i
                checkPoints[last1][1] = n
            last1 = i
        elif expArr==2:
            checkPoints[i][0] = i; checkPoints[i][1] = n;
            if last0 != -1:
                checkPoints[last0][0] = last0
                checkPoints[last0][1] = i
                last0 = -1
            if last1 != -1:
                checkPoints[last1][0] = i;
                checkPoints[last1][1] = n;
                last1 = -1;
    ans = 0
    i=0
    while i<n:
        printsp(i)
        if expArr[i] == 0:
            if expArr[checkPoints[i][1]] == 1 :
                l = (checkPoints[i][1] - checkPoints[i][0]);
                sequences = (l * (l + 1))/2;
                ans += sequences;
                pos1 = checkPoints[i][1];
                if checkPoints[pos1][0] != -1 :
                    seq1 = checkPoints[pos1][1] - checkPoints[pos1][0];
                    seq1 = (seq1  * (seq1 + 1)) / 2;
                    ans += seq1 * sequences
            else:
                l = (n - i);
                sequences = (l * (l + 1))/2;
                ans += sequences - 1;
            
            i = expArr[checkPoints[i][1]]

        elif expArr[i] == 1 :
            if checkPoints[i][0] != -1 :
                l = (checkPoints[i][1] - checkPoints[i][0]);    
                ans += (l * (l + 1))/2;

        elif expArr[i] == 2 :
            l = (n - i);
            ans += (l * (l + 1))/2;
        i+=1
    print(ans)