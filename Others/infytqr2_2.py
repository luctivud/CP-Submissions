def get_list()      : return list(map(int, input().strip().split()))

a = get_list()
b = get_list()

sum1, sum2 = sum(a), sum(b)
setB = set(b)

outOdd = [];outEven = []
for i in a:
	newSumA = sum1 - i
	diff = (sum2 + i - newSumA)
	if (diff & 1):
		continue
	else:
		diff = diff // 2
	if diff in setB:
		if (i * diff) & 1:
			outOdd.append((i, diff))
		else:
			outEven.append((i, diff))

outEven.sort(key = lambda x: x[0] * x[1])
outOdd.sort(key = lambda x: -(x[0] * x[1]))

if (sum1 == sum2) or (len(outEven) == 0 and len(outOdd) == 0):
	print(-1)
else:
	ans = ""
	for i in outEven:
		ans += str(i[0]) + ',' + str(i[1]) + ','
	for i in outOdd:
		ans += str(i[0]) + ',' + str(i[1]) + ','
	print(ans.strip(','))

