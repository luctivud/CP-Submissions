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
def dictCC(d, permutli, zeroIndegree):
    for k, v in d.items():
        checkEl = set()
        if len(permutli[k-1]) != 1:
            for el in v:
                if el in zeroIndegree:
                    checkEl.add(el)
            if len(checkEl) == 1:
                for ele in checkEl:
                    zeroIndegree.remove(ele)
                    permutli[k-1] = [ele]
    return d, permutli, zeroIndegree
def validate(revNode, permutli):
    forComp = []
    boo = False
    for k, v in revNode.items():
        if len(v) == 1:
            boo = True
            for el in v:
                forComp.append([k,el])
    if boo:
        revNode, permutli = revNodeCC(revNode, permutli, forComp)
        return revNode, permutli
    else:
        return revNode, permutli
def revNodeCC(revNode, permutli, forComp):
    for ele in forComp:
        permutli[ele[1]-1] = [ele[0]]
        for k, v in revNode.items():
            try:
                v.remove(ele[1])
            except:
                pass
    revNode, permutli = validate(revNode, permutli)
    return revNode, permutli
# ###################################################################################
import itertools
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
    revNode = {}
    for k, v in d.items():
        for val in v:
            try:
                revNode[val].add(k)
            except:
                revNode[val] = set()
                revNode[val].add(k)
    permutli = [ [] for x in range(n) ]
# ############################################################
    revNode, permutli = validate(revNode, permutli)
# ############################################################
    for key, val in d.items():
        if len(permutli[key-1])>0:
            continue
        elif len(val) >= 1:
            for i in d[key]:
                permutli[key-1].append(i)
        else:
            permutli[key-1].append(0)
    # print(permutli)
    # revNodeCC()
    zeroIndegree = {x for x in range(1, n+1)}
    for i in range(n):
        if len(permutli[i]) == 1:
            try:
                zeroIndegree.remove(permutli[i][0])
            except:
                pass
    d, permutli, zeroIndegree = dictCC(d, permutli, zeroIndegree)
    revNode, permutli = validate(revNode, permutli)
    # allpermutations = list(itertools.product(*permutli))
    # count = n+2;    ansli = [];
    # for perm in allpermutations:
    #     se = set()
    #     for i in perm:
    #         se.add(i)
    #     sz = 0
    #     for num in range(1, n+1):
    #         if num not in se:
    #             sz+=1
    #     if sz < count:
    #         count = sz
    #         ansli = list(perm).copy()
    # print(count)
    count = 0; ansli = [0]*n
    for i in range(n):
        if len(permutli[i]) == 1:
            try:
                zeroIndegree.remove(permutli[i][0])
            except:
                pass
    for i in range(n):
        for j in permutli:
            boo = False
            for k in j:
                if k in zeroIndegree:
                    ansli[i] = k
                    boo = True
                    zeroIndegree.remove(k)
                    break
                else:
                    ansli[i] = permutli[i][0]
            if boo == True:
                break
    for i in range(1, n+1):
        if i not in ansli:
            count+=1
    print(count)
    for ele in ansli:
        print(ele, end = " ")
    print()