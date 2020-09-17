n = int(input())
for i in range(9, 0, -1):
    if n % i == 0:
        d = i
        break
print(n//d)
print((str(d)+' ')*(n//d))
