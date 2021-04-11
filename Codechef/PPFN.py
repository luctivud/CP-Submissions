#				 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/					 #


import math;   		from collections import *
import sys;   		from functools import reduce
import time;   		from itertools import groupby

# sys.setrecursionlimit(10**6)

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

# for _test_ in range(int(input())): 
li = ['2', '3', '5', '7', '11', '101', '131', '151', '181', '191', '313', '353', '373', '383', '727', '757', '787', '797', '919', '929', '10301', '10501', '10601', '11311', '11411', '12421', '12721', '12821', '13331', '13831', '13931', '14341', '14741', '15451', '15551', '16061', '16361', '16561', '16661', '17471', '17971', '18181', '18481', '19391', '19891', '19991', '30103', '30203', '30403', '30703', '30803', '31013', '31513', '32323', '32423', '33533', '34543', '34843', '35053', '35153', '35353', '35753', '36263', '36563', '37273', '37573', '38083', '38183', '38783', '39293', '70207', '70507', '70607', '71317', '71917', '72227', '72727', '73037', '73237', '73637', '74047', '74747', '75557', '76367', '76667', '77377', '77477', '77977', '78487', '78787', '78887', '79397', '79697', '79997', '90709', '91019', '93139', '93239', '93739']

cnt = Counter(input())
ans = []
for i in li:
	c1 = Counter(i)
	if not(c1 - cnt):
		ans.append(i)

if len(ans) == 0:
	ans.append(-1)
print(*ans)




