n = int(input())
ans = [1]*10
this = 1; i = 0
while this < n:
    i %= 10
    this //= ans[i]
    ans[i] += 1
    this *= ans[i]
    i += 1
s = 'codeforces'
for i in range(10):
    print(s[i] * ans[i], end = "")
print()