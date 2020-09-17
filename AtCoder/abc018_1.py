import numpy as np

li = []
for i in range(3):
    li.append(int(input()))
# print(li)
li = np.array(li)
li = li.argsort()
print(li)