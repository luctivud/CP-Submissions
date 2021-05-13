N = 20
for i in range(4, N):
	print("count{}[{}] = {{0}}".format(i, i), end=", ")
print()
for i in range(4, N):
	print("count{}[m % i % {}] += 1;".format(i, i))

for i in range(4, N):
	print("ans += count{}[m % {}] - countMod[m % {}];".format(i, i, i))
