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


import math;   		from collections import *
import sys;   		from functools import reduce
import time;   		from itertools import groupby

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


def calculate(lis, n):
	# print(lis)
	sz = len(lis)
	if sz == 0:
		return
	if sz == 1:
		removedToyTime[n-sz] = max(enjoyment[lis[0]], removedToyTime[n-sz])
		return 
	flag = True
	timeSpent = 0
	temp = dict()
	for i in range(2*sz):
		if i >= sz:
			if timeSpent - temp[lis[i%sz]] >= remember[lis[i%sz]]:
				timeSpent += enjoyment[lis[i%sz]]
			else:
				flag = False
				break
		else:
			timeSpent += enjoyment[lis[i%sz]]
			temp[lis[i]] = timeSpent
	# print(temp)
	if flag:
		timeSpent = float('inf')
	removedToyTime[n-sz] = max(timeSpent, removedToyTime[n-sz])


def solve(ind, n, lis):
	# print(ind)
	if ind == n:
		calculate(lis, n)
		return
	lisCopy1 = lis.copy()
	lisCopy2 = lis.copy()
	lisCopy1.append(ind)
	solve(ind+1, n, lisCopy1)
	solve(ind+1, n, lisCopy2)

# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

for _test_ in range(int(input())): 
	enjoyment = []
	remember = []
	n = int(input())
	for nn in range(n):
		a, b = get_ints()
		enjoyment.append(a)
		remember.append(b)
	removedToyTime = defaultdict(int)
	# solve(0, n, [])
	# print(removedToyTime)
	sz = n
	removed = 0
	lis = list(range(n))
	temp = dict()
	timeSpent = 0
	fac = 0
	for i in range(2*sz):
		if i >= sz:
			if timeSpent - fac - temp[lis[i%sz]] >= remember[lis[i%sz]]:
				timeSpent += enjoyment[lis[i%sz]]
			else:
				removed += 1
				fac += enjoyment[lis[i%sz]]
				removedToyTime[n-sz] = max(timeSpent, removedToyTime[n-sz])
		else:
			timeSpent += enjoyment[lis[i%sz]]
			temp[lis[i]] = timeSpent


	maxTime = 0; minRemove = n
	for ke, va in removedToyTime.items():
		if va > maxTime:
			maxTime = va
			minRemove = ke
	if maxTime == float('inf'):
		maxTime = 'INDEFINITELY'


	if maxTime == float('inf'):
		maxTime = 'INDEFINITELY'

	# print(maxTime, minRemove)
	print("Case #{}: {} {}".format(_test_+1, minRemove, maxTime))





