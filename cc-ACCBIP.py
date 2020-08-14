''' 			tmluctivud 			'''


# solution designed for subtask 2 and 3.
# can be essentially improved by introducing dict for similar slopes.

import sys 
from collections import defaultdict
from math import factorial
import heapq

sys.setrecursionlimit(int(1e5))

def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())

INF = float('inf')




# Util to calculate Triangles



# Using dp to solve knapsack N*k







# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


for _test_ in range(int(input())): # Test Cases
	n, c, k = get_ints()
	# color count to store count of slopes of a particukar type
	color_count = [defaultdict(int) for x in range(c)] 
	for i in range(n):
		ai, bi, ci = get_ints()
		color_count[ci-1][ai] += 1
	# cost of erasing a line
	cost_erase = get_list()
	
	dp = [[-1] * (k+1) for x in range(n)]
	# print(color_count)

	initialTriangles = calculateTriangles()
	# print(dp)



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






# # precompute nc3 for n's using the recurrence relation : C3(n) = (n / (n-3)) * C3(n-1)
# NC3_list = [0, 0, 0, 1]
# def precomputeNC3(n):
# 	for i in range(4, n+1):
# 		NC3_list.append(int((i/(i-3)) * NC3_list[i-1]))
# 	# print(NC3_list[-1])

# # helper to return NC3_list item
# def getNC3(n: int):
# 	return NC3_list[n]


# precomputeNC3(3005)	# precomputeNC3's for O(1) access



# # Util to calculate Triangles:
# def calculateTriangles(color_count):
# 	ans = 0
# 	for i in color_count:
# 		ans += getNC3(i)
# 	return ans






# # recursively solve using dynamic programming => memoization of tuples
# def NotSolve(eraser_length, color_count):
# 	# print(eraser_length, color_count)
# 	# tupled_color_count = tuple(color_count)

# 	if eraser_length not in dp:
# 		ok = False	
# 		mini = INF
# 		# find minimum triangles for every turn till eraser is availb
# 		for i in range(c):
# 			if (eraser_length - v[i] >= 0 and color_count[i] > 0):
# 				ok = True
# 				color_count_copy = color_count.copy()
# 				color_count_copy[i] -= 1
# 				xen = solve(eraser_length - v[i], color_count_copy)
# 				mini = min(mini, xen)
# 		if not ok:
# 			mini = calculateTriangles(color_count)
# 		dp[eraser_length] = mini
# 	return dp[eraser_length]