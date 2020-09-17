for _ in range(int(input())):
    n = int(input())
    se = set()
    flag = True
    for i in range(1, (2*n)+1):
        se.add(i)
    li = list(map(int, input().split()))
    flagForOne = False
    for ele in li:
        if ele == 1:
            flagForOne = True
        if ele == 2*n:
            flag = False
        se.remove(ele)
    if flagForOne == False:
        flag = False
    if flag == False:
        print("-1", end = "")
    else:
        newli = []
        for ele in li:
            newli.append(ele)
            srch = ele + 1
            while True:
                if srch in se:
                    newli.append(srch)
                    se.remove(srch)
                    break
                else:
                    srch+=1
        for ele in newli:
            print(ele, end=" ")
    print()


