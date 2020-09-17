n = int(input())
s = input()
Fr = Se = 0
prev = s[0]
for i in range(1, n):
    if s[i] != prev:
        if s[i] == 'F':
            Fr += 1
        else:
            Se += 1
    prev = s[i]
# print(Se, Fr)
print("YES" if Fr > Se else "NO")