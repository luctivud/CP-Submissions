#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# Udit Gupta @luctivud  神 | LIGHT | GREED | CIPHER | XAYN
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
                ##     ##   ######   # #  ######
                ##     ##   ##  ##   ###    ##
                ##     ##   ##   #   # #    ##
                ###### ##   ######   # #    ##
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#                   | WORSHIPPER OF GREED | 
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
import collections
for _testcases_ in range(int(input())):
    n = int(input())
    p, q = map(int, input().split())
    k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    li = list(map(int, input().split()))
    s = collections.Counter(li)

    fkill = 0; fassist = 0; dkill = 0; dassist = 0;
    binaryString = input()
    for i in range (n):
        binary = binaryString[i]
        if binary == '0':
            si = k[i] + a[i]
            try:
                s[si]-=1
                if s[si]>=0:
                    fkill += k[i]
                    fassist += a[i]
            except:
                pass
        else:
            si = k[i] + a[i]
            try:
                s[si]-=1
                if s[si]>=0:
                    dkill += k[i]
                    dassist += a[i]
            except:
                pass
    fscore = (p*fkill)+(q*fassist)
    dscore = (p*dkill)+(q*dassist)
    if fscore>dscore:
        print("Frost")
    else:
        print("DustinKiller")