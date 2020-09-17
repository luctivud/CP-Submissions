import sys

sys.stdout = open('input.txt', 'w')

print(1)

from random import randint
n = randint(1, 100)
print(n)
for i in range(n):
    print(randint(1, int(1e2)), end=" ")