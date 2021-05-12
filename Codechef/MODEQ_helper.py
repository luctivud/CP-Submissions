''' 
	************************.- J A I  S H R E E  R A M -.*************************

	  ::: ---------- ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	      Author   :  Udit "luctivud" Gupta 

	      linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
	      github   :  https://github.com/luctivud

	  :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ---------- :::

'''

import math, sys, collections, functools, time, itertools;

# sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>





def solveEachTest(_TestCase):
	# printsp("Case #{}: ".format(_TestCase)) 
	n = 16; m = 25; ans = 0
	n, m = Read_Ints()
	cnt = collections.defaultdict(int)
	for a in range(1, n+1):
		for b in range(a+1, n+1):
			# v = b * (m // b)
			if (a == b) : continue;
			if ((m % a) % b == (m % b) % a):
				# if not (v / a == v // a):
				# if (a == 5 or b == 5):
				# 	print(a, b)
				ans += 1
				# print(a, b)
				cnt[a] += 1
				# cnt[b] += 1
	print(cnt)
	print(ans)
	d = collections.defaultdict(list)
	for i in range(1, n+1):
		d[m % i].append(i)
	print(*sorted(d.items(), key = lambda x : -len(x[1])))
	# print([(i, m % i) for i in range(1, n+1)])

	# m = 67681
	# se = set()
	# for i in range(1, 1000):
	# 	se.add(i * (m // i))
	# # print(se)
	# print(min(se), max(se), - min(se) + max(se))


_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

