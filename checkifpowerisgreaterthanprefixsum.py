i = 1
k = 4
prev = 0
while i < 10:
	num = i ** k
	print(num, prev)
	prev += num
	i += 1