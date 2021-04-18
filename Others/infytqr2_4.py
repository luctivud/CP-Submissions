def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())

m = int(input())
q = int(input())

a = []
b = []
for i in range(m):
	a.append(get_list())
for i in range(q):
	b.append(get_list())

n, p = len(a[0]), len(b[0])

ans = [[0 for x in range(len(a[0]))] for y in range(m)];

def isValid(i, j):
	return i >= 0 and i < q and j >= 0 and j < p

from collections import defaultdict
for i in range(m):
	for j in range(n):
		cnt = defaultdict(int)
		li = []
		for ii in (i, j):
			for jj in (i, j):
				if (isValid(ii, jj)):
					pro = a[i][j] * b[ii][jj]
					cnt[pro] += 1
					li.append(pro)
		li.sort(key = lambda x : (cnt[x], x))
		if len(li) == 0:
			res = -1
		else:
			res = li[0];
		ans[i][j] = res
for i in ans:
	print(*i)




