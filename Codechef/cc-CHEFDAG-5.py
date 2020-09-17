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
# import itertools
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
    se = { x for x in range(1,n+1) }
    permutli = [ [] for x in range(n) ]
    print(d)
    # print(se)
    for key, val in d.items():
        if len(val) == 1:
            for i in d[key]:
                permutli[key-1].append(i)
                se.remove(i)
        elif len(val) > 1:
            for i in d[key]:
                permutli[key-1].append(i)
        else:
            permutli[key-1].append(0)
    # print(permutli)
    revNode = {}
    for k, v in d.items():
        for val in v:
            try:
                revNode[val].add(k)
            except:
                revNode[val] = set()
                revNode[val].add(k)
    print(revNode)
    for k, v in revNode.items():
        if len(v) == 1:
            for i in v:
                if len(permutli[i-1]) != 1:
                    permutli[i-1] = [k]
                    se.remove(k)
    print(se)
    # allpermutations = list(itertools.product(*permutli))
    count = n+2;    ansli = [];
    
    print(count)
    for ele in ansli:
        print(ele, end = " ")
    print()