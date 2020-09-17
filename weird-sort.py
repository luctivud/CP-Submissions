for _ in range(int(input())):
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    ind = set(map(int, input().split()))
    brr = sorted(arr)
    flag = True
    for i in range(len(arr)):
        if arr[i]!=brr[i]:
            if i not in ind and i-1 not in ind:
                flag = False
                break
    if flag:
        print("YES")
    else:
        print("NO")