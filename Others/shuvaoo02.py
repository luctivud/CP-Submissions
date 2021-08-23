n = int(input())
li = list(map(int, input().split()))

li = li[::-1]
li.append(0)
ans = 0
for i in range(n+1):
    if li[i] + 1 <= 9:
        break
    else:
        ans = n-i-1
print(ans)