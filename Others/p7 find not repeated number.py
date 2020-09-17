li = list(map(int, input().split()))
d = {}
for ele in li:
    if d[ele]:
        d[ele]+=1
    else:
        d[ele] = 0