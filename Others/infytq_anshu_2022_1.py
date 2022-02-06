from itertools import groupby
def getNextTerm(a):
	return "".join([str(len(list(va))) + ke for ke, va in groupby(str(a))])
a = int(input())
n = int(input())
ans = [a]
for i in range(n-1):
	a = getNextTerm(a)
	ans.append(a)
print(*ans, sep=",")