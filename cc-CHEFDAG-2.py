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
    # print(d)
    ansDict = {}
    oneEle = []
    moreThanOneEle = []
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
    countRevNode = {}
    revNode = {}
    for ele in moreThanOneEle:
        for val in d[ele]:
            try:
                revNode[val].add(ele)
                countRevNode[val]+=1
            except:
                revNode[val] = set()
                revNode[val].add(ele)
                countRevNode[val]=1

    # print(ansDict)
    # print(revNode)
    # print(countRevNode)
    # print(sorted(countRevNode.items(), key = lambda kv:(kv[1], kv[0])))
    for key, val in sorted(countRevNode.items(), key = lambda kv:(kv[1], kv[0])):
        if len(revNode[key]) == 1:
            for ele in revNode[key]:
                ansDict[ele] = key
                visitedNodes.add(key)
                break
        else:
            flag = False
            for ele in revNode[key]:
                try:
                    if ansDict[ele]:
                        pass
                except:
                    ansDict[ele] = key
                    visitedNodes.add(key)
                    break
                
    # print(ansDict)
    count = 0
    ansli = []
    cse = set()
    for i in range(1,n+1):
        ansli.append(ansDict[i])
        cse.add(ansDict[i])
    for i in range(1, n+1):
        if i not in cse:
            count += 1
    print(count)
    for ele in ansli:
        print(ele, end= " ")
    print()