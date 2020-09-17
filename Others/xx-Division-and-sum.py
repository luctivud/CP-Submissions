k = 10
for i in range(k):
    n = int(input())
    n -= 1
    ans = 0
    for i in range(1, n+1):
        ans += (n//i)
    print(n+1, ans)
