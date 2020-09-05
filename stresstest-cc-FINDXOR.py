li = [2, 4, 7, 10]
realans = 0
for i in li:
	realans ^= i
print(1)
print(len(li))
for i in range(20):
	number = 1 << i;
	ans = 0
	for j in li:
		ans += number ^ j
	print(ans, ans >> (i))


print("real ans", realans)