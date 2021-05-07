a = int(input())
b = int(input())
n = ((((2*(a+b)) + 0.25)) - 0.5) ** 0.5
n = int(n)
if (n * (n+1)) == 2*(a+b):
	num = 0
	for i in range(n, 0, -1):
		if a >= i:
			a -= i
			num += 1
	print(num)
else:
	print("-1")