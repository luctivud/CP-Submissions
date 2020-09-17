for _ in range(int(input())):
    a,b,p = map(int, input().split())
    s = input()
    n = len(s); prev = 'C'; pay=0; sta = n
    li =[0]
    for i in range(n-2, -1,-1):
        if s[i] != prev:
            prev = s[i]
            pay += b if prev == 'B' else a
        li.append(pay)
    li.reverse()
    # print(li)
    for i in range(len(li)):
        if li[i]<=p:
            sta = i+1
            break
    print(sta)
