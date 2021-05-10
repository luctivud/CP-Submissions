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
	# k = int(input())
	k = _TestCase
	# print(k)
	li = []
	
	for i in range(1, 2*k+2):
		li.append(k+(i**2))
	# print(li)
	gc = []
	ans = 0
	for i in range(2*k):
		gc.append(math.gcd(li[i], li[i+1]))
	ans = []
	for (ke, va) in sorted(collections.Counter(gc).items()):
		ans.append((ke, va, ke*va))
	if True or len(ans) > 5:
		print(["{}:{} = {}".format(a, b, c) for a, b, c in ans])
		# print(li)
		# print(gc)
		print([(gc[-1]-len(gc)+i+1, gc[i]) for i in range(len(gc))])
		print()
	# print((k, sum(gc)))
	# printsp(sum(gc))






_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

