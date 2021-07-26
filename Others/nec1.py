a = set(list(map(int, input().split())))
b = set(list(map(int, input().split())))

print(len(a) - len(a-b))
