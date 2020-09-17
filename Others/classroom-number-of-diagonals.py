for _ in range(int(input())):
    n = int(input())
    if n > 2:
        print((n*(n-3))//2)
    else:
        print("Not Possible")