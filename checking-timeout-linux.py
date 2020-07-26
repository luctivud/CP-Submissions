print("before")
li = [0, 1, 2, 2]
ind = 1
for i in range(3, 10000000):
    li.extend([i] * li[i])
print(len(li))