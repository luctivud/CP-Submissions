def get_ints() : return map(int, input().split())
def get_list() : return list(get_ints())
import sys 
sys.setrecursionlimit(int(1e5))


def solve(i, table, number_of_tables, number_of_extras):
	print(i, table, number_of_tables, number_of_extras)
	if (i >= n):
		return number_of_extras + number_of_tables * k
	currCost = number_of_extras + number_of_tables * k
	if li[i] in table:
		if currCost not in dp[i]:
			if table[li[i]] == 1:
				table[li[i]] += 1
				dp[i][currCost][1] = solve(i+1, {li[i] : 1}, number_of_tables+1, number_of_extras)
				dp[i][currCost][0] = solve(i+1, table, number_of_tables, number_of_extras+2)
			else:
				table[li[i]] += 1
				dp[i][currCost][1] = solve(i+1, {li[i] : 1}, number_of_tables+1, number_of_extras)
				dp[i][currCost][0] = solve(i+1, table, number_of_tables, number_of_extras+1)
	else:
		table[li[i]] = 1
		if currCost not in dp[i]:
			dp[i][currCost][0] = solve(i+1, table, number_of_tables, number_of_extras)
			dp[i][currCost][1] = solve(i+1, {li[i] : 1}, number_of_tables+1, number_of_extras)
			# return dp[i][currCost][0]
	return min(dp[i][currCost][0], dp[i][currCost][1])	


from collections import defaultdict
for _ in range(int(input())):
	n, k = get_ints()
	li = get_list()
	dp = [dict() for x in range(1005)]
	print(solve(0, {}, 1, 0))		
	# print(dp)
