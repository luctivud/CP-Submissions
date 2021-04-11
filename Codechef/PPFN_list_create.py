li = []
while True:
	try:
		a, b = input().split()
		li.append(b)
	except:
		break
print(li)