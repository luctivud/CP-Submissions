import sys
import random
from random import randint
sys.stdout = open('input.txt', 'w')

print(4)
for _ in range(4):
    n = 1000000
    m = randint(1, n)
    print(n, m)
    for i in range(n):
        print(randint(1, int(1e9)))