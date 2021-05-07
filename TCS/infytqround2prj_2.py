mod = int(1e9) + 7
# n = int(input())
s = list(input())
# li = list(map(int, input().split()))
import collections
d = collections.defaultdict(int)
for i in range(9):
	d[chr(i + ord('1'))] = int(input())

flag = False
n = len(s)
for i in range(n):
	if flag:
		if int(s[i]) > d[s[i]]:
			break
		else:
			s[i] = str(d[s[i]])
	else:
		if int(s[i]) < d[s[i]]:
			s[i] = str(d[s[i]])
			flag = True
# print(s)
# print("".join(s))
ans = 0
for i in range(n-1, -1, -1):
	pos = n - i - 1
	ans += (int(s[i]) * pow(10, pos, mod))
	ans %= mod
print(ans % mod)
print(58832646452639258958 % mod)