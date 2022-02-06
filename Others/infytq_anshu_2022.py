import sys
sys.setrecursionlimit(int(1e6))
def solve(i, curr_prod, curr_li):
	if curr_prod == prod and len(curr_li):
		ans.append(curr_li.copy())
		return
	if i == len(li) or curr_prod > prod:
		return
	curr_li.append(li[i])
	solve(i, curr_prod * li[i], curr_li)
	curr_li.pop()
	solve(i+1, curr_prod, curr_li)

li = sorted(list(map(int, input().split(","))))
prod = int(input())
ans = []
solve(0, 1, [])
if not len(ans):
	print("-1")
for i in ans:
	print(*i, sep=",")

