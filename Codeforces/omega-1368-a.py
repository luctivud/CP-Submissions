for _ in range(int(input())):
    a, b, n = map(int, input().split())
    a, b = max(a, b), min(a, b)
    count = 0
    while a <= n:
        a, b = a+b, a
        count += 1
    print(count)