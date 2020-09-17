prev = None; ans = 0
for i in range(int(input())):
    s = input()
    if s != prev:
        ans += 1
    prev = s
print(ans)