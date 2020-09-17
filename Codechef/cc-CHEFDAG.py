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
    refli = [0]*n
    li2 = []
    for ki in range(k):
        li = list(map(int, input().split()))
        if ki == 0:
            refli = li.copy()
        if ki > 0:
            for i in range(min(len(li2),len(li))):
                if li[i] != li2[i]:
                    refli[i] = 0
                else:
                    refli[i] = li[i]
        # for i in range (n):
        #     for j in range(i):
        #         try:
        #             d[li[i]].remove(li[j])
        #         except:
        #             pass
        li2 = li.copy()
    # print(refli)
    ans = {}
    oneEle = []
    count = 0
    firstOne = 0
    for i in range(len(refli)):
        if refli[i] == 0:
            # count+=1
            oneEle.append(i)
        else:
            if firstOne == 0:
                firstOne = refli[i]
            else:
                ans[li[i-1]] = {li[i]}
    for ele in oneEle:
        ans[li2[ele]] = {firstOne}
    # print(oneEle,firstOne,ans)
    ansli = []
    se = set()
    for i in range(1,n+1):
        try:
            el = 0
            for el in ans[i]:
                ansli.append(el)
                se.add(el)
                break
        except:
            ansli.append(0)
    # print(count, ansli)
    for i in range(1, n+1):
        if i not in se:
            count += 1
    print(count)
    for ele in ansli:
        print(ele, end = " ")
    print()


    ########################################################################################

    # moreThanOneEle = []
    # for key, val in d.items():
    #     ans[key] = 0
    #     if len(val) == 1:
    #         oneEle.append(key)
    #     if len(val) > 1:
    #         moreThanOneEle.append(key)
    # for ele in oneEle:
    #     i = 0
    #     for i in d[ele]:
    #     	ans[ele] = i
    #     for mto in moreThanOneEle:
    #         try:
    #             d[mto].remove(i)
    #         except:
    #             pass
    # for ele in moreThanOneEle:
    #     if len(d[ele]) == 1:
    #         for i in d[ele]:
    #             ans[ele] = i
    #     else:
    #         ans[ele] = 0
    # # print(d,oneEle,moreThanOneEle,ans)
    # # print(ans)
    # ansli = []
    # for i in range(1,n+1):
    #     if ans[i] == 0:
    #         count += 1
    #     ansli.append(ans[i])
    # print(count)
    # for i in ansli:
    #     print(i, end = " ")
    # print()
