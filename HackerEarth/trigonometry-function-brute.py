import math
li = [0]

prev, mod = 0, int(1e9)+21
for i in range(100):
	num1 = (2 * (math.cos(i * 0.71372437895816)))
	num2 = (7 ** (i / 2)) % mod
	num3 = (i * 4 ** i) % mod
	ans = (num3 + round(num1 * num2)+ mod) % mod
	# print(num3, prev+ans, prev, ans)
	li.append(prev+ans)
	prev = li[-1]
print(li)

t = int(input())
while t:
	t -= 1
	l, r = map(int, input().split())
	print(li[r+1] - li[l])