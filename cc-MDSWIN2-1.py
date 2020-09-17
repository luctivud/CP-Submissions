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
def checkIfMagicOddWillYield(magicNums):
    for i in magicNums:
        magicNumsCpy = magicNums.copy()
        magicNumsCpy.remove(i)
        if checkIfMagicEvenWillYield(magicNumsCpy) == True:
            return False
    return True
def checkIfMagicEvenWillYield(magicNums):
    fightingLength = []
    for i in range(2, 1+len(magicNums)+1):
        if i not in magicNums:
            fightingLength.append(i)
    if len(fightingLength)%2 == 1 :
        return True
    else:
        return False
# ##########################################################
def nCr(n, r): 
    return (fact(n) // (fact(r) * fact(n - r))) % 998244353

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
        multiCountNums = []; singleCount = 0; magicNums = [];
        ans = 0
        for k, v in countNumbers.items():
            if k == 1:
                singleCount = v
            else:
                multiCountNums.append(k)
                if v%2==1:
                    magicNums.append(k)
        # print(multiCountNums, singleCount, magicNums)
        magicNumsLength = len(magicNums)
    # #################################################################
        if magicNumsLength%2 == 0:
            if magicNumsLength == 0:
                if singleCount%2 == 0:
                    ans = 0
                else:
                    fightingLength =[]
                    for i in range(2, len(multiCountNums)+2):
                        if i not in multiCountNums:
                            fightingLength.append(i)
                    if len(fightingLength)%2 == 1:
                        for i in multiCountNums:
                            pass
            # #############################################
                    ans += singleCount
            else:
                if singleCount%2 == 0:
                    if len(magicNums)%4 != 0:
                        magicNums.sort(reverse = True)
                        for i in range(magicNumsLength):
                            choi = 0
                            for j in range(i+1, magicNumsLength):
                                choi += nCr(magicNums[i], magicNums[j])
                            ans += countNumbers[magicNums[i]] * choi
                    else:
                        for i in multiCountNums:
                            magicNumsCpy = magicNums.copy()
                            if i not in magicNums:
                                magicNumsCpy.append(i)
                                if checkIfMagicOddWillYield(magicNumsCpy) == True:
                                    ans += countNumbers[i]
                        for i in multiCountNums:
                            magicNumsCpy = magicNums.copy()
                            if i not in magicNums:
                                magicNumsCpy.append(i)
                                magicNumsCpy.append(i-1)
                                if checkIfMagicEvenWillYield(magicNumsCpy) == False:
                                    ans += countNumbers[i] * i
                else:
                    if checkIfMagicEvenWillYield(magicNums) == False:
                        ans = singleCount
                    fightingLength = []
                    for i in range(2, 1+len(magicNums)+1):
                        if i not in magicNums:
                            fightingLength.append(i)
                    if len(fightingLength)%2 == 1 :
                        for j in magicNums:
                            if j > len(fightingLength)+1:
                                for i in fightingLength:
                                    ans += countNumbers[j] * nCr(j, i)
    # #########################__ODD_MAGIC__###########################################
        else:
            if magicNumsLength == 1:
                if singleCount%2 == 0:
                    for i in magicNums:
                        ans += countNumbers[i]
                else:
                    for i in magicNums:
                        ans += (countNumbers[i] * i)
            else:
                if singleCount%2 == 0:
                    for i in magicNums:
                        magicNumsCpy = magicNums.copy()
                        magicNumsCpy.remove(i)
                        if checkIfMagicEvenWillYield(magicNumsCpy) == False:
                            ans += (countNumbers[i] * i)
                else:
                    for i in magicNums:
                        magicNumsCpy = magicNums.copy()
                        magicNumsCpy.remove(i)
                        if checkIfMagicEvenWillYield(magicNumsCpy) == False:
                            ans += countNumbers[i]
                    fightingLength = []
                    for i in range(2, 1+len(magicNums)+1):
                        if i not in magicNums:
                            fightingLength.append(i)
                    if len(fightingLength)%2 == 1 :
                        for j in magicNums:
                            if j > len(fightingLength)+1:
                                for i in fightingLength:
                                    ans += countNumbers[j] * nCr(j, i)
        print(ans % 998244353)