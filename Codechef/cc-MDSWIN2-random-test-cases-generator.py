import random
from random import randint
t = randint(1,10)
print(t)
for i in range(t):
    n = randint(1,4)
    print(n)
    for j in range(n):
        print(randint(1,4), end= " ")
    print()
    print(1)
    print(1,n)