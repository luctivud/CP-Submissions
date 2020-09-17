n = 14
s = 0
for i in range(1, n+1):
	s += i ** 3
	print(i**3, end = ",")

print("\n", s//2)