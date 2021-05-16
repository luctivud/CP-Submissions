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
	n, q = Read_Ints()
	s = list(input())

	cnt = collections.Counter(s)

	for qq in range(q):
		query = list(input().split())
		query[1] = int(query[1]) - 1
		if query[0] == '1':
			cnt[s[query[1]]] -= 1
			s[query[1]] = query[2]
			cnt[s[query[1]]] += 1
			print(cnt)
		# else:
		# 	if (len(cnt)) < query[1]:
		# 		print(-1)
		# 	else:
		# 		ans, cou = sorted(cnt.items(), key = lambda x: (-x[1], x[0]))[query[1]-1]
		# 		if cou:
		# 			print(ans)
		# 		else:
		# 			print(-1)






_T0T4 = 1;
_T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)



# 0.2s Domain Expansion  :
#				  	MAHAYANA PRISON 

