'''     ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█  
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     '''



import math;   from collections import *
import sys;    from functools import reduce
import time;   from itertools import groupby

# sys.setrecursionlimit(10**6)

def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (+1, -1)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]


CAPS_ALPHABETS = {chr(i+ord('A')) : i for i in range(26)}
SMOL_ALPHABETS = {chr(i+ord('a')) : i for i in range(26)}
INF = float('inf')


# Custom input output is now piped through terminal commands.


S34t = time.time()
# for _testcases_ in range(int(input())): 
# sys.stdin = open('output.txt', 'r')
sys.stdin = open('output.txt', 'r')
sys.stdout = open('resultTest.txt', 'w')

from random import randint


# match = []
# f = open('input.txt', 'r')
# for line in f.readlines():
# 	try:
# 		a, b = get_ints()
# 		match.append(b)
# 	except:
# 		pass

def solve():
	tree = defaultdict(list)
	n = int(input())
	# print(n)
	for i in range(n-1):
		a, b = get_ints()
		tree[a].append(b)
		tree[b].append(a)
	# print(tree)
	visited = set()
	visited.add(1)
	queue = deque()
	queue.append((1, 0))
	ans = 0
	while (len(queue)):
		this = queue.popleft()
		node, dep = this
		# print(n, dep)
		for n in tree[node]:
			if n not in visited:
				visited.add(n)
				queue.append((n, dep+1))
				ans += dep+1
	print(ans)

# IN = open('output.txt', 'r')
for i in range(10):
	# solve()
	try:
		solve()
	except:
		print(i, "ok2")
		pass
# # print("Time Elapsed: {}".format(float(S34p-S34t)))
