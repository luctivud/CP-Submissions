from random import randint
import random
t = randint(1,20)
print(t)
for test in range(t):
    n = randint(2, 10)
    k = randint(1, 10)
    print(n, k)
    li = [x for x in range(1, n+1)]
    for ts in range(k):
        random.shuffle(li)
        for i in li:
            print(i, end = " ")
        print()
    print()