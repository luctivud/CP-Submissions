ans = 0
for i in range(1, 101):
	ans += i ** 3
	ans %= 19
print(ans)