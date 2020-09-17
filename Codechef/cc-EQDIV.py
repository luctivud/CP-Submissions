"""MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:,'..'xXWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO. .:kOo.,kNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO. .lNWWo..lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MNOxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxMMMMWKxoloxKWNc  .:xxd;  ,dxxxkXMXkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxMM
MKc''''''''''''''''.  ..'''''.   .''''.  .''MMMWx..,:. .xXo''.  .''.  ..'';kMk;'''''.  .'.''.  .''''''.  ..''.   .''MM
MWNXNNNNNNNNNNNNNNNO' ;KNNNNNKo. cKNNNd. lXNMMMK; ,0Wx. :NWXXl .dNNO' ;KNNNWMWNNNNNXc .kNNNNx. cXNNNNNO' ;KNN0; 'ONNMM
MMMMMMMMMMMMMMMMMWM0' :NMMMMWMX: .OMWWx. oWMMMMWx. ';. .dNMWWo .xMM0' :NWWMMMMMMMMWWl .OMMMWk. lWWMMWM0' ;XMMX: ,KMMMM
MMMMMMWMWkccccccccc;. :NMWNNNKd. :XMMWx. oWMMMWKo. .',. .,ldx; .dMM0' :NMMMMMMMNNWMWl .OMMMWk. lWMMMMM0' ;XMMX: ,0MMMM
MMWXKNWMWxcc,. .;cc;. :XMk,''..'lKWMMWx. oWMNx:. .lONNKxl.     .xMM0' :NMMMMMM0:,oKO' ,KMMMMk. lWWNkoc,. .;::;. ,KMMMM
MMXc.lXMMWWWNd..xWM0' :NM0;  ;kXWMMMWNl  oWMK:.;xXWWMWXx:. ,c' .dMM0' :NMMMMMMKc. ...;kWMMMMk. lWWc .:;. .clc:. ,KMMMM
MWWx. lXMWMMMK, lWM0' :NMMNx'.,ldxxoc'   oWMWNKNWWWN0o' .:kNWo .dMM0' :NMMMMMMMNO;  ,OWWWMMMk. lWM' lXx. lNMMX: ,KMMMM
MMMWk'.,xKNX0c..kWM0' :NMMMMNkl;,'',:l:  oWMMMMMWMWO' 'l0WMWWo .xMM0' :NMMMMMMMMMNd. .oXWMMMk. lWMd.....;0WMMX: ,KMMMM
MMMMWKo'...'..:kWMM0' :NMMMMMMMWWNNWWWx. oWMMMMMMMMWOxXWMWMWWo .xMM0' :NMMMMMMMMMMMKl. ,kNMMk. lWMWKkxx0NMWMMX: ,KMMMM
MMMMMMMN0kxk0XNWMMWKl;xNMMMMMMMMMMMMWM0c;kWMMMMMMMMMMMWWMMMMWk;:OMMXl,dNMMMMMMMMMMMMWO; .dNM0c;kWWMMMMMMMMMMMNd,oXMMMM
MMMMMMMMWWMWMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMWWMMWMMMMMMMMMMMMMMNkxKWMMWWMMMMMMMMMMMMMMWMMWMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"""


#				 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/					 #


# import math;   		from collections import *
# import sys;   		from functools import reduce
# import time;   		from itertools import groupby

import sys
sys.setrecursionlimit(10**5)

# def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (+1, -1)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]



# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


from heapq import heapify, heappush, heappop




def find_repr(x):
	if x != parent[x]:
		parent[x] = find_repr(parent[x])
	return parent[x]


def Union(x, y):
    x = find_repr(x);
    y = find_repr(y);

    if (x == y):  return

    if (rank[x] < rank[y]) :
        parent[x] = y;
    elif (rank[x] > rank[y]) :
        parent[y] = x;
    else:
        parent[y] = x;
        rank[x] = rank[x] + 1;
    return;



maxn = int(1e6) + 5
def precompute(k):
	for i in range(1, maxn):
		raisedToPower.append(i ** k)


raisedToPower = []

k = int(input())
precompute(k)
for _test_ in range(int(input())): 
	n = int(input())
	parent = [i for i in range(n+1)]
	rank = [0] * (n+1)
	heap = [(-raisedToPower[i-1], i, i) for i in range(1, n+1)]
	heapify(heap)

	for ss in range(n-1):
		hairu = heappop(heap)
		ihehi = heappop(heap)
		kaneki = hairu[0] - ihehi[0]
		# print(hairu)
		# print(ihehi)

		if hairu[1] == hairu[2] and ihehi[1] == ihehi[2]:
			heappush(heap, (kaneki, find_repr(ihehi[1]), find_repr(hairu[2])))
		elif hairu[1] == hairu[2] or ihehi[1] == ihehi[2]:
			if hairu[1] == hairu[2]:
				Union(hairu[1], ihehi[1])
				heappush(heap, (kaneki, find_repr(ihehi[2]), find_repr(ihehi[1])))
			else:
				Union(hairu[1], ihehi[1])
				heappush(heap, (kaneki, find_repr(hairu[1]), find_repr(hairu[2])))
		else:
			Union(hairu[2], ihehi[1])
			Union(hairu[1], ihehi[2])
			heappush(heap, (kaneki, find_repr(hairu[1]), find_repr(hairu[2])))

	print(-heappop(heap)[0])
	ans = [0] * (n+1)
	fac = find_repr(1)
	for i in range(1, n+1):
		if find_repr(i) == fac:
			printxsp("0")
		else:
			printxsp("1")
	print()










