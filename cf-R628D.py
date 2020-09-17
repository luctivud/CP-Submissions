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
# for _testcases_ in range(int(input())):
def checkXor(n, u, v):
    li = [1]*n
    rem = v - n
    if n % 2 == 0:
        if rem == u:
            return n, li.append(rem), True
        else:
            checkXor(n+1, u, v)
u, v = map(int, input().split())
if u == 0:
    print(0)
elif v == 0:
    if v>u and v%2==0:
        print(2)
        print(v//2, v//2)
    else:
        print(-1)
elif v == 1:
    if u==1:
        print(1)
        print(1)
    else:
        print(-1)
else:
    i = 1
    j = v-1
    if i ^ j == u:
        print(2)
        print(i, j)
    else:
        if (v - u) >= 0 and (v-u)%2 == 0:
            print(3)
            print((v-u)//2, (v-u)//2, u)
        else:
            n, li, boo = checkXor(4,u,v)