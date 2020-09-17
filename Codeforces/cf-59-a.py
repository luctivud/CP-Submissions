s = input()
up = lo = 0
for i in s:
    if i.isupper(): up += 1
    elif i.islower(): lo += 1
print(s.upper() if up > lo else s.lower())