s = input().strip('0')
n = len(s)
ok = True
for i in range(n//2):
	ok &= s[i] == s[n-i-1]
print("Yes" if ok else "No")