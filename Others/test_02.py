def check(a, b):
    res = 0
    for i in range(len(a)):
        res += a[i] != b[i]
    return res

t = int(input())
for x in range(t):
    a = input()
    b = input()
    n, m = len(a), len(b)
    ans = n
    for i in range(n-m+1):
        ans = min(ans, check(a[i:i+m], b))
    print(ans)
