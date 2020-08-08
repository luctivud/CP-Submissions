# def get_ints() : return map(int, input().split())
# def get_list() : return list(get_ints())
# import sys 
# sys.setrecursionlimit(int(1e5))


# def solve(i, table, number_of_table, number_of_extra):
# 	# print(i, table)
# 	ans = number_of_table * k + number_of_extra
# 	if i == n:
# 		return ans
# 	familyMember = li[i]
# 	if familyMember in table:
# 		newTable = table.copy()
# 		newTable[familyMember] += 1
# 		# if dp[i][ans] == float('inf'):
# 		# 	dp[i][ans] = min(, dp[i][ans])
# 		if dp[i][number_of_table][number_of_extra] == float('inf'):
# 			if table[familyMember] == 1:
# 				dp[i][number_of_table][number_of_extra] = \
# 				min(solve(i+1, newTable, number_of_table, number_of_extra+2),\
# 				 solve(i+1, {familyMember : 1}, number_of_table+1, number_of_extra))
# 			else:
# 				dp[i][number_of_table][number_of_extra] = \
# 				min(solve(i+1, newTable, number_of_table, number_of_extra+1),\
# 				 solve(i+1, {familyMember : 1}, number_of_table+1, number_of_extra))

# 	else:
# 		table[familyMember] = 1
# 		if dp[i][number_of_table][number_of_extra] == float('inf'):
# 			dp[i][number_of_table][number_of_extra] = solve(i+1, table, number_of_table, number_of_extra)
# 	return dp[i][number_of_table][number_of_extra]


# from collections import defaultdict
# for _ in range(int(input())):
# 	n, k = get_ints()
# 	li = get_list()
# 	dp = [[defaultdict(lambda : float('inf'))] * (n+1) for x in range(n+1)]
# 	print(solve(0, {}, 1, 0))
# 	# print(dp)

def get_ints() : return map(int, input().split())
def get_list() : return list(get_ints())
import sys 
sys.setrecursionlimit(int(1e5))


def solve1(i, d, ans, extra):
	# print(i, d, ans, extra)
	if i >= n:
		return ans + extra
	# dp[i][ans // k]
	if li[i] in d:
		# if dp[i][ans//k+1] == float('inf'):
		dp[i][ans//k+1] = solve1(i+1, {li[i] : 1}, ans+k, extra)
		if d[li[i]] == 1:
			extra += 2
		else:
			extra += 1
		d[li[i]] += 1
		# if dp[i][ans//k] == float('inf') :
		dp[i][ans//k] = min(dp[i][ans//k], solve1(i+1, d, ans, extra))
	else:
		d[li[i]] = 1
		# if dp[i][ans//k] == float('inf'):
		dp[i][ans//k] = solve1(i+1, d, ans, extra)
			# dp[i][1] = dp[i][0]

	return min(dp[i][ans//k], dp[i][ans//k+1])


def solve(i, d, ans, extra):
	# print(i, d, ans, extra)
	if i >= n:
		return ans + extra
	# dp[i][ans // k]
	if li[i] in d:
		if dp[i][ans//k+1] == float('inf'):
			dp[i][ans//k+1] = solve(i+1, {li[i] : 1}, ans+k, extra)
		if d[li[i]] == 1:
			extra += 2
		else:
			extra += 1
		d[li[i]] += 1
		if dp[i][ans//k] == float('inf') :
			dp[i][ans//k] = min(dp[i][ans//k], solve(i+1, d, ans, extra))
	else:
		d[li[i]] = 1
		if dp[i][ans//k] == float('inf'):
			dp[i][ans//k] = solve(i+1, d, ans, extra)
			# dp[i][1] = dp[i][0]

	return min(dp[i][ans//k], dp[i][ans//k+1])

for _ in range(int(input())):
	n, k = get_ints()
	li = get_list()
	dp = [[float('inf')] * (1005) for x in range(1005)]
	if n*n < 1e4:
		print(solve1(0, {}, k, 0))
	else:
		print(solve(0, {}, k, 0))
	# print(dp)
# sorry for exploiting the test case, i'll resubmit ig