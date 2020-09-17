import math
import sys
# sys.stdin = open("output.txt",'r')
# sys.stdout = open("ans000.txt", 'w')
def cuberoot(n):
	return math.ceil(n ** (1/3))
li = list(map(int, input().split()))
pos = set()
for i in li:
	cr = cuberoot(i)
	assert (cr ** 3 == i)
	pos.add(cr)
	# print(cuberoot(i), end=" ")
n = 14
for i in range(n):
	if i+1 in pos:
		print("1", end="")
	else:
		print("0", end="")
