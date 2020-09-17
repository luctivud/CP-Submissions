for _ in range(int(input())):
    res=''
    li = list(input().split())
    if len(li[0])>1:
        res+=li[0][1].upper()
        res+=li[0][2::]
        res+=li[0][0].lower()
    else:
        res+=li[0]
    res+='ay '
    for i in range(1,len(li)):
        if len(li[i])>1:
            res+=li[i][1::]
            res+=li[i][0]      
        else:
            res+=li[i]
        res+='ay '
    print(res)