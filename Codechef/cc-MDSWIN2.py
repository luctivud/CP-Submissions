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
def nCr(n, r): 
    return (fact(n) // (fact(r) * fact(n - r))) 

def fact(n): 
    res = 1
    for i in range(2, n+1): 
        res = res * i 
    return res 
# ##########################################################
for _testcases_ in range(int(input())):
    n = int(input())
    li = list(map(int, input().split()))
    for _query_ in range(int(input())):
        d = {};  countNumbers = {}
        l, r = map(int, input().split())
        for i in range(l-1, r):
            try:
                d[li[i]] += 1
            except:
                d[li[i]] = 1
        for k, v in d.items():
            try:
                countNumbers[v] += 1
            except:
                countNumbers[v] = 1
        # print(countNumbers)
        multiCountNums = [];  singleNumCount = 0; checkMultiCountEven = 0; forIter = []; sameCount = []
        ans = 0
        for k, v in countNumbers.items():
            if k == 1:
                singleNumCount = v
            else:
                if v%2 == 1:
                    forIter.append(k)
                if v>1 and v%2==0:
                    sameCount.append(k)
                multiCountNums.append(k)
                checkMultiCountEven += v%2
        forIter.sort(reverse = True)
        # print(multiCountNums, checkMultiCountEven, singleNumCount)
        if checkMultiCountEven == 1:
            if countNumbers[multiCountNums[0]] == 1:
                if singleNumCount%2 == 0:
                    ans = 1
                else:
                    for ele in multiCountNums:
                        ans = (ele)
            else:
                if countNumbers[multiCountNums[0]]%2 == 1:
                    if singleNumCount%2 == 0:
                        for ele in multiCountNums:
                            ans = (countNumbers[ele]*1) 
                    else:
                        ans = 0
        elif checkMultiCountEven>1:
            if ((checkMultiCountEven%2)+(singleNumCount%2))%2 == 1:
                ans = 0
            else:
                ans += singleNumCount
                sz = len(forIter)
                for i in range(sz):
                    for j in range(i+1, sz):
                        ans += countNumbers[forIter[i]]*nCr(forIter[i], forIter[j])
        else:
            if singleNumCount%2==1:
                ans = 1
        print(ans)