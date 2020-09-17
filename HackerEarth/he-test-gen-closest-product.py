from random import randint

n = randint(1, 20)
# k = randint(1, 1000)
# print(n, k)
arr = []
for i in range(n):
	arr.append(randint(1, 100))
brr = []
for i in range(n):
	brr.append(randint(1, 100))
minRange = maxRange = 0
arr.sort(); brr.sort();
for i in range(n):
	minRange += (arr[i] * brr[n-i-1])
	maxRange += (arr[i] * brr[i])
k = randint(minRange, maxRange)
print(n, k)
print(*arr)
print(*brr)
