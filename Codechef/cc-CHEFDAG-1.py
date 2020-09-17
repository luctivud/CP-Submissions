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
for __ in range(int(input())):
    n, k = map(int, input().split())
    d = {}
    for i in range(1,n+1):
        for j in range (1,n+1):
            if j!=i:
                try:
                    d[i].add(j)
                except:
                    d[i] = set()
                    d[i].add(j)
    # print(d)
    for ki in range(k):
        li = list(map(int, input().split()))
        for i in range (n):
            for j in range(i):
                try:
                    d[li[i]].remove(li[j])
                except:
                    pass
    ansDict = {}
    moreThanOneEle = []
    oneEle = []
    for key, val in d.items():
        if len(val) == 1:
            oneEle.append(key)
        elif len(val) > 1:
            moreThanOneEle.append(key)
        else:
            ansDict[key] = 0
    visitedNodes = set()
    for ele in oneEle:
        i = 0
        for i in d[ele]:
            visitedNodes.add(i)
            ansDict[ele] = i
    oneEle = []
    ascenDict = {}
    for ele in moreThanOneEle:
        ascenDict[ele] = len(d[ele])
    # print(ascenDict)
    for key, val in sorted(ascenDict.items(), key = lambda kv:(kv[1], kv[0])):
        # print(key,val)
        flag = False
        for ele in d[key]:
            if ele not in visitedNodes:
                visitedNodes.add(ele)
                ansDict[key] = ele
                flag = True
                break
            else:
                continue
        if flag == False:
            for i in d[key]:
                ansDict[key] = i
                break
    ansli = []
    cse = set()
    count = 0
    for i in range(1,n+1):
        ansli.append(ansDict[i])
        cse.add(ansDict[i])
    # print(len(countZeroes))
    for i in range(1, n+1):
        if i not in cse:
            count += 1
    print(count)
    for ele in ansli:
        print(ele, end= " ")
    print()