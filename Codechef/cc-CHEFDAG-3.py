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
# def construct(ansDict, revNode, node):
#     for i in revNode[node]:
#         ansDict[i] = node
#         break
#     return ansDict
#     # ansDict, boo = validate(ansDict, revNode)
#     # if boo:
#     #     return ansDict
#     # else:

# ########################################################
# def validate(ansDict, revNode):
#     unfairAssign = []
#     cse = set()
#     for i in range(1,n+1):
#         cse.add(ansDict[i])
#     for i in range(1,n+1):
#         if i not in cse:
#             try:
#                 if revNode[i]:
#                     unfairAssign.append(i)
#             except:
#                 pass
#     return unfairAssign
# ##########################################################
for __ in range(int(input())):
    n, k = map(int, input().split())
    d = {}
    if n == 1:
    	print(1)
    	print(1)
    else:
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
        # # print(len(countZeroes))
        # cse = set()
        # for i in range(1,n+1):
        #     ansli.append(ansDict[i])
        #     cse.add(ansDict[i])
        # unfairAssign = validate(ansDict, revNode)
        countInDegree = {}

        for v,k in ansDict.items():
            if k != 0:
                try:
                    countInDegree[k].add(v)
                except:
                    countInDegree[k] = set()
                    countInDegree[k].add(v)
        # print(countInDegree)
        cse = set()
        for i in range(1, n+1):
            cse.add(ansDict[i])
        for key, val in countInDegree.items():
            if len(val) > 1:
                for ele in val:
                    for i in d[ele]:
                        if i not in cse:
                            cse.add(i)
                            ansDict[ele] = i
        # print(ansDict)
        ansli = []
        cse = set()
        for i in range(1, n+1):
            ansli.append(ansDict[i])
            cse.add(ansDict[i])
        count = 0
        for i in range(1, n+1):
            if i not in cse:
                count += 1
        print(count)
        for ele in ansli:
            print(ele, end= " ")
        print()
