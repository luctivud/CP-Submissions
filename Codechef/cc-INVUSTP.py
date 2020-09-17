from bisect import bisect_left

def getSum(BITree, index): 
	s = 0
	while index > 0: 
		s += BITree[index] 
		index -= index & (-index) 
	return s 


def updateBIT(BITree, n, index, val): 
	while index <= n: 
		BITree[index] += val 
		index += index & (-index) 


def makeBIT(arr, n):  
	temp = [0] * n 
	for i in range(n): 
		temp[i] = arr[i] 
	temp.sort() 
	for i in range(n): 
		arr[i] = bisect_left(temp, arr[i]) + 1


def findElements(arr, n): 
	makeBIT(arr, n) 
	BIT = [0] * (n + 1) 
	res = [0] * n 
	for i in range(n): 
		res[i] = i - getSum(BIT, arr[i]) 
		updateBIT(BIT, n, arr[i], 1) 
	return res



# main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

n, q = map(int, input().split())
arr = list(map(int, input().split()))

res = findElements(arr, n)

# print(res)

prefix_sum = [0]
currsum = 0
for i in res:
	currsum += i
	prefix_sum.append(currsum)

# print(prefix_sum)

for qq in range(q):
	l, r = map(int, input().split())
	print(prefix_sum[r] - prefix_sum[l-1])



''' code taken from article : open-source @ https://www.geeksforgeeks.org/count-smaller-elements-on-right-side-and-greater-elements-on-left-side-using-binary-index-tree/'''