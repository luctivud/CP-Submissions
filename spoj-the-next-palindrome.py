for _ in range(int(input())):
    n = int(input())
    n = str(n)
    sz = len(n)
    res = ''
    sz = len(n)
    if sz%2==0:
        n1 = n[:sz//2:]
        res = n1+n1[::-1]
        if int(res)<=int(n):
            n1 = str(int(n1)+1)
            res = n1+n1[::-1]
    else:
        n1 = n[:sz//2:]
        n2 = n[sz//2]
        res = n1+n2+n1[::-1]
        if int(res)<=int(n):
            n2 = str(int(n2)+1)
            res = n1+n2+n1[::-1]
    print(res)