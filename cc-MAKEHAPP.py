a = 172
b = 9
for i in range(5):
	print(a, b)
	a, b = b, ~(a^b)