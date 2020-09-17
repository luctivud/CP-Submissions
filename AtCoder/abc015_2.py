n = int(input())
li = list(map(int, input().split()))
s = 0; count = 0
for i in li:
    if i != 0:
        s += i
        count += 1
print(round(s/count))