''' 
	************************.- J A I  S H R E E  R A M -.*************************

	  ::: ---------- ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	      Author   :  Udit "luctivud" Gupta 

	      linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
	      github   :  https://github.com/luctivud

	  :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ---------- :::

'''

import math, sys, collections, functools, time, itertools;

sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



def dfs(node, par, dep, adj):
	children = []
	# print(node, par, dep)
	if node == 1:
		# battle of bastards here
		for i in adj[node]:
			children.append(dfs(i, node, dep+1, adj))
		print(children)
		res = [[0, 0]]
		for child in children:
			child.sort(key = lambda x : -x[1])
			minEl = child[-1]
			maxEl = child[0]
		return res
	else:
		# union here
		for i in adj[node]:
			if i != par:
				children.extend(dfs(i, node, dep+1, adj))
		if len(children) == 0:
			return [[node, dep]]
		return children






def solveEachTest(_TestCase):
	# printsp("Case #{}: ".format(_TestCase)) 
	n = int(input())
	adj = collections.defaultdict(list)
	for i in range(n-1):
		a, b = Read_Ints()
		adj[a].append(b)
		adj[b].append(a)
	ans = dfs(1, 0, 0, adj)
	time = ans[0][1]
	ans.sort(key = lambda x : x[0])
	print(len(ans), time)
	for i in ans:
		printsp(i[0])
	print()
	






_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

