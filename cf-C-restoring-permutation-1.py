for _ in range(int(input())):
    n = int(input())
    se = set()
    flag = True
    li = list(map(int, input().split()))
    for ele in li:
        se.add(ele)
    newli = []
    for ele in li:
        newli.append(ele)
        srch = ele + 1
        if srch>2*n:
        	flag = False
        	break
        while True:
            if srch not in se:
                newli.append(srch)
                se.add(srch)
                break
            else:
                srch+=1
            if srch>2*n:
                flag = False
                break
    if flag == False:
        print("-1", end = "")
    else:
        for ele in newli:
            print(ele, end=" ")
    print()


