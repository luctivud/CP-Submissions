ok = False
ans = ""
while (not ok):
	print("0")
	try:
		ans += input()
	except:
		ok = 1
print(ans)