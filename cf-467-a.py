n = int(input())
from functools import reduce
print(len(list(filter(lambda x: x>1, [reduce(lambda x, y: y-x, list(map(int, input().split()))) for i in range(n)]))))