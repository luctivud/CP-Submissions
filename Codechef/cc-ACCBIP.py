''' 			tmluctivud 			'''


# solution designed for subtask 1 and 3. # for small task
# [done] can be essentially improved by introducing dict for similar slopes.

import sys 
from collections import defaultdict
from math import factorial
import heapq
from copy import deepcopy

sys.setrecursionlimit(int(1e5))

def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())

INF = float('inf')


# make my color baby badass:
def makeColorBadass(color_count):
	for i in range(c):
		sou = 0; sos = 0; soc = 0
		# print(color_count[i])
		# if len(color_count[i]) >= 3:
		for ke, val in color_count[i].items():
			sou += val
			sos += (val ** 2)
			soc += (val ** 3)
		color_count[i]['sou'] = sou
		color_count[i]['sos'] = sos
		color_count[i]['soc'] = soc
	return color_count


# Util to calculate Triangles init 
def calcTrianglesInitUtil(color_count):
	triangles = 0
	# (σ1^3 − 3.σ1.σ2 + 2.σ3) // 6
	for i in range(c):
		sou = color_count[i]['sou']
		sos = color_count[i]['sos']
		soc = color_count[i]['soc']
		s1 = sou ** 3
		s2 = 3 * sou * sos
		s3 = 2 * soc
		ans = (s1 - s2 + s3) // 6
		color_count[i]['T'] = max(0, ans)
		triangles += max(0, ans)
	return triangles


# impplement formula
def UtilFormulate(slope_color_dict):
	sou = slope_color_dict['sou']
	sos = slope_color_dict['sos']
	soc = slope_color_dict['soc']
	s1 = sou ** 3
	s2 = 3 * sou * sos
	s3 = 2 * soc
	ans = (s1 - s2 + s3) // 6
	# print(ans)
	return max(0, ans)





# Util to calculate Triangles in O1
def UtilFixTriangles(color_count_copy, i, triangles):
	fixedTriangles = triangles
	slope_line_del = slopes[i]
	color_type_line_del = color_types[i]
	triangles_contri_by_color = color_count_copy[color_type_line_del]['T']
	fixedTriangles -= triangles_contri_by_color
	number_slope_color_del = color_count_copy[color_type_line_del][slope_line_del]
	color_count_copy[color_type_line_del]['sou'] -= number_slope_color_del
	color_count_copy[color_type_line_del]['sos'] -= number_slope_color_del ** 2
	color_count_copy[color_type_line_del]['soc'] -= number_slope_color_del ** 3
	# print(color_count_copy)
	number_slope_color_del -= 1
	color_count_copy[color_type_line_del][slope_line_del] -= 1
	color_count_copy[color_type_line_del]['sou'] += number_slope_color_del
	color_count_copy[color_type_line_del]['sos'] += number_slope_color_del ** 2
	color_count_copy[color_type_line_del]['soc'] += number_slope_color_del ** 3
	fixedTriangles += UtilFormulate(color_count_copy[color_type_line_del])
	fixedTriangles = max(0, fixedTriangles)
	color_count_copy[color_type_line_del]['T'] = fixedTriangles
	return fixedTriangles, color_count_copy





# Using dp to solve knapsack N*k
def solve(i, eraser_length, triangles, color_count):
	# print(i, eraser_length, triangles, color_count)
	if i == n:
		return triangles
	if dp[i][eraser_length] == -1:
		if cost_erase[color_types[i]] > eraser_length:
			dp[i][eraser_length] = solve(i+1, eraser_length, triangles, color_count)
		else:
			color_count_copy = deepcopy(color_count.copy())
			# O(1)
			fixedTriangles, color_count_copy = UtilFixTriangles(color_count_copy, i, triangles)
			dp[i][eraser_length] = min(solve(i+1, eraser_length, triangles, color_count ) , \
				solve(i+1, eraser_length - cost_erase[color_types[i]], fixedTriangles, color_count_copy))
	return dp[i][eraser_length]







# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


for _test_ in range(int(input())): # Test Cases
	n, c, k = get_ints()
	# color count to store count of slopes of a particukar type
	color_count = [defaultdict(int) for x in range(c)] 
	slopes = []
	color_types = []
	for i in range(n):
		ai, bi, ci = get_ints()
		slopes.append(ai)
		color_types.append(ci-1)
		color_count[ci-1][ai] += 1
	# cost of erasing a line
	cost_erase = get_list()
	
	dp = [[-1] * (k+1) for x in range(n)]
	# print(dp)
	# O(n)
	color_count = makeColorBadass(color_count)
	# O(c)
	Triangles = calcTrianglesInitUtil(color_count)
	# print(color_count)
	# print(Triangles)
	# O(n*k)
	print(solve(0, k, Triangles, color_count))
	# for i in dp:
	# 	print(*i)



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