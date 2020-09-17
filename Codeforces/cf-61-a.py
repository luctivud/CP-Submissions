s = input()
t = input()
for i in range(len(s)):
    print(str(int(s[i]) ^ int(t[i])), end = '')
print()