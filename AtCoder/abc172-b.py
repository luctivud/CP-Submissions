s = input()
t = input()
count = 0
for i in range(min(len(s), len(t))):
    if s[i] != t[i]:
        count += 1
print(count)