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
# #################################################
import itertools
def createFromRevnode(revNode, d, zeroIndegree, oneOutdegree, ansli):
    oneLength = []; boo = False; outRemove = set()
    for k, v in revNode.items():
        tempCount = 0
        for el in v:
            tempCount+=1
        if tempCount == 1:
            oneLength.append(k)
    for ele in oneLength:
        boo = True
        for i in revNode[ele]:
            if i not in oneOutdegree:
                oneOutdegree.add(i)
                ansli[i-1]=ele
                zeroIndegree.discard(ele)
                outRemove.add(i)
        del revNode[ele]
    d = reconstructD(d, outRemove)
    revNode = reconstructRevnode(revNode, outRemove)
    return revNode, d, zeroIndegree, oneOutdegree, ansli, boo
    
def reconstructRevnode(revNode, outRemove):
    for outr in outRemove:
        for k, v in revNode.items():
            v.discard(outr)
    return revNode

        
def createFromD(revNode, d, zeroIndegree, oneOutdegree, ansli):
    oneLength = []; boo = False;
    for k, v in d.items():
        tempCount = 0
        for el in v:
            tempCount += 1
        if tempCount == 1:
            oneLength.append(k)
    for ele in oneLength:
        boo = True
        if ele not in oneOutdegree:
            for i in d[ele]:
                ansli[ele-1] = i
                oneOutdegree.add(ele)
                zeroIndegree.discard(i)
    d = reconstructD(d, oneLength)
    return revNode, d, zeroIndegree, oneOutdegree, ansli, boo
    
def reconstructD(d, oneLength):
    for ele in oneLength:
        del(d[ele])
    return d
# #################################################
for _test_ in range(int(input())):
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
    for ki in range(k):
        li = list(map(int, input().split()))
        for i in range (n):
            for j in range(i):
                try:
                    d[li[i]].remove(li[j])
                except:
                    pass
    revNode = {}
    for k, v in d.items():
        for val in v:
            try:
                revNode[val].add(k)
            except:
                revNode[val] = set()
                revNode[val].add(k)
    # ###############--CREATE--ALL--POSSIBLE--###################
    zeroIndegree = { x for x in range(1, n+1) }
    oneOutdegree = set()
    ansli = [0]*n
    changeBool = True
    while(changeBool):
        boolRevnode = True; boolD = True;
        countTurn = 0
        while(boolRevnode or boolD):
            revNode, d, zeroIndegree, oneOutdegree, ansli, boolRevnode = createFromRevnode(revNode, d, zeroIndegree, oneOutdegree, ansli)
            revNode, d, zeroIndegree, oneOutdegree, ansli, boolD = createFromD(revNode, d, zeroIndegree, oneOutdegree, ansli)
            countTurn += 1
        if countTurn <= 1:
            changeBool = False
    # boolRevnode = True; boolD = True;
    # while(boolRevnode or boolD):
    #     revNode, d, zeroIndegree, oneOutdegree, ansli, boolRevnode = createFromRevnode(revNode, d, zeroIndegree, oneOutdegree, ansli)
    #     revNode, d, zeroIndegree, oneOutdegree, ansli, boolD = createFromD(revNode, d, zeroIndegree, oneOutdegree, ansli)
    # ####################--ANS--################################
    # forRemove = []
    # # print(zeroIndegree)
    # print(d)
    # for i in zeroIndegree:
    #     try:
    #         for ele in revNode[i]:
    #             if ele not in oneOutdegree:
    #                 oneOutdegree.add(ele)
    #                 ansli[ele - 1] = i
    #                 forRemove.append(i)
    #                 break
    #     except:
    #         pass
    # # print(forRemove)
    # for i in forRemove:
    #     zeroIndegree.discard(i)
    # print(ansli)
    permutli = [[] for x in range(n)]
    for i in range(n):
        if ansli[i]!=0:
            permutli[i].append(ansli[i])
        else:
            try:
                sz = len(d[i+1])
                if sz != 0:
                    for ele in d[i+1]:
                        permutli[i].append(ele)
                else:
                    permutli[i].append(0)
            except:
                permutli[i].append(0)
    allpermutations = list(itertools.product(*permutli))
    count = n+2;    ansli = [];
    for perm in allpermutations:
        se = set()
        for i in perm:
            se.add(i)
        sz = 0
        for num in range(1, n+1):
            if num not in se:
                sz+=1
        if sz < count:
            count = sz
            ansli = list(perm).copy()
    # for i in range(1, n+1):
    #     if i in zeroIndegree:
    #         count += 1
    print(count)
    for ele in ansli:
        print(ele, end = " ")
    print()