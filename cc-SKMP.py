''' 			tmluctivud 			'''

import sys 
from collections import defaultdict
from math import factorial
import heapq


def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())

INF = float('inf')


# precompute nc3 for n's using the recurrence relation : C3(n) = (n / (n-3)) * C3(n-1)
NC3_list = [0, 0, 0, 1]
def precomputeNC3(n):
	for i in range(4, n+1):
		NC3_list.append(int((i/(i-3)) * NC3_list[i-1]))
	# print(NC3_list[-1])


# recursively solve using dynamic programming => memoization
def solve(color_index, eraser_length, color_count):
	if eraser_length < 0: 
		return INF
	if color_index == c:
		return 0
	if dp[color_index][eraser_length] == INF:
		for i in range(c):
			if eraser_length - v[i] >= 0:
				dp[color_index][eraser_length] = min(dp[color_index][eraser_length], \
					solve(i, eraser_length-v[i]))
	return dp[color_index][eraser_length]




# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
precomputeNC3(3005)	# precomputeNC3's for O(1) access


for _test_ in range(int(input())): # Test Cases
	n, c, k = get_ints()
	color_count = [0] * (c+1)
	for i in range(n):
		ai, bi, ci = get_ints()
		color_count[ci] += 1
	v = get_list() + [INF]
	dp = [[INF]*(k+1) for x in range(n)]

	print(solve(0, k, color_count))



# Wasted part of code kept as reference: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	# heap = [-i for i in color_count.values()]
	# heapq.heapify(heap)
	# while k - v[0] >= 0:
	# 	k -= v[0]
	# 	num = heapq.heappop(heap)
	# 	heapq.heappush(heap, num + 1)
	# ans = 0
	# for i in heap:
	# 	i = -i
	# 	if i >= 3:
	# 		ans += nC3(i)
	# print(ans)





