''' 
	************************.- J A I  S H R E E  R A M -.*************************

	  ::: ---------- ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	      Author   :  Udit "luctivud" Gupta 

	      linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
	      github   :  https://github.com/luctivud

	  :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ---------- :::

'''

import math, sys, collections, functools, time, itertools;

sys.setrecursionlimit(int(3e6))


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

mod = int(1e9) + 7;


def findValue(node, parent, adj):
	res = 1
	children = []
	for i in adj[node]:
		if i != parent:
			children.append(findValue(i, node, adj))
	children.sort();
	sz = len(children)
	for i in range(sz):
		res += ((sz - i) * (children[i]));
	return res 



def solveEachTest(_TestCase):
	# printsp("Case #{}: ".format(_TestCase)) 
	n, x = Read_Ints();
	x %= mod;
	adj = collections.defaultdict(list)
	for i in range(n-1):
		a, b = Read_Ints()
		adj[a].append(b)
		adj[b].append(a)
	print((findValue(1, 0, adj) * x) % mod)






_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

