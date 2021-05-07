import collections
n = int(input())
m = int(input())
d = collections.defaultdict(int);
for _ in range(n):
	d[int(input())] += 1
ans = 0
for ke in range(1, m+1):
	res = d[ke] // 3
	ans += res
	d[ke] -= res * 3

for ke in range(1, m+1):
	if d[ke]>0 and d[ke+1] > 0 and d[ke+2] > 0:
		res = min(d[ke], d[ke+1], d[ke+2])
		ans += res
		d[ke] -=  res
		d[ke+1] -= res
		d[ke+2] -= res

print(ans)