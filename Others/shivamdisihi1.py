for _ in range(int(input())):
    n = int(input())
    arr = list(map(lambda x : int(x) % 4, input().split()))
    print(len(list(filter(lambda x : x % 4 == 0, \
        [(arr[i] + arr[j]) for i in range(n) for j in range(i+1, n)]))))

