#`````````````````````````````````````#
    ##     ##   ######   # #  ######
    ##     ##   ##  ##   ###    ##
    ##     ##   ##   #   # #    ##
    ###### ##   ######   # #    ##
#`````````````````````````````````````#
n = int(input())
roboc = list(map(int, input().split()))
bionic = list(map(int, input().split()))
rcount = 0; bcount = 0; csame = 0
for i in range(n):
    if roboc[i]>bionic[i]:
        rcount+=1
    elif roboc[i]<bionic[i]:
        bcount+=1
    else:
        csame+=1
import math
ans = -1
if csame == n:
    ans = -1
else:
    if rcount == 0:
        ans = -1
    else:
        ans = math.ceil((bcount+1)/rcount)
print(ans)
