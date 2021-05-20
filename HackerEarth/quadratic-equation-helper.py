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
	se = set()
	for i in range(int(1e5)):
		se.add(i *i)
	cnt = collections.defaultdict(int)

	for c in range(1, 100):
		for b in range(1, 100):	
			if (b ** 2 - c) in se:
				cnt[c] += 1;
				# if c == 15:
				# 	print(b)

	print(sorted(cnt.items(), key = lambda x: x[0]))
	res = 0
	for i in range(1, 35):
		printsp(cnt[i])



_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

