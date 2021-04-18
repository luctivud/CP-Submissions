s = input()
ans = ""
for i in s:
	if i.isnumeric():
		ans += i;
print(int(ans))