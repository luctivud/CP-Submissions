from random import randint
edges = set()
n = randint(1, int(16))
m = randint(n-1, n)
print(n, m)
print(randint(1, n), randint(1, n))
while m > 0:
	a = randint(1, n)
	b = randint(1, n)
	while b == a:
		b = randint(1, n)
	a, b = min(a, b), max(a, b)
	if ((a, b) not in edges):
		edges.add((a, b))
		m -= 1
for i in edges:
	print(*i)
