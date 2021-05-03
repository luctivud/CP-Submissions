import math
def ncr2(n):
	return math.factorial(n) // math.factorial(n//2) ** 2
# print(12164510040883200 // (ncr2(20) // 2 * math.factorial(9) ** 2))
print(ncr2(400) % 234567899)