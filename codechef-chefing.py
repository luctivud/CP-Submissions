for _ in range(int(input())):
    charse = set()
    for i in range(0,26):
        charse.add(i)
    # print(charse)
    for __ in range(int(input())):
        s = input()
        se = set()
        for i in s:
            se.add(ord(i)-ord('a'))
        li =[]
        for ele in charse:
            if ele not in se:
                li.append(ele)
        for ele in li:
            charse.remove(ele)
    print(len(charse))