
import math;   		from collections import *
import sys;   		from functools import reduce
import time;   		from itertools import groupby

# sys.setrecursionlimit(10**6)

def input()         : return sys.stdin.readline().strip('\n')
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")


def makeTrie(s, stringIndex) :
	temp = mintrie
	for ind, val in enumerate(s):
		temp = temp.setdefault(val , {})
	temp[chr(ord('z')+2)] = stringIndex
	# maxtrie
	temp = maxtrie
	for ind, val in enumerate(s):
		temp = temp.setdefault(val , {})
	temp['A'] = stringIndex


def getMinInd(trie) : #return minind
	temp = trie
	while True:
		mnVal = min(temp)
		# print(mnVal)
		if mnVal == '|':
			return temp['|']
		temp = temp[mnVal]



def getMaxInd(trie) : #return maxind
	temp = trie
	while True:
		mnVal = max(temp)
		# print(mnVal)
		if mnVal == 'A':
			return temp['A']
		temp = temp[mnVal]

def addTrie(ind, ch):
	# print(ind, c)
	ind-=1
	stemp = list_of_strings[ind]
	# print(stemp)
	# s += c
	temp1 = mintrie
	temp2 = maxtrie
	ismin = True
	ismax = True
	for i in stemp:
		# print(i, temp1)
		if i < min(temp1):
			ismin = False
		if i > max(temp2):
			ismax = False
		temp1 = temp1[i]
		temp2 = temp2[i]
	# print(ch, min(temp1))
	if ch < min(temp1):
		ismin = False
		temp1[ch] = {}
	# print(ch, max(temp2), ismax)
	if ch > max(temp2):
		ismax = False
		temp2[ch] = {}	
	temp1[chr(ord('z')+2)] = n
	temp2['A'] = n
	if not ismin:
		# print('ok')
		global minind
		minind = n
	if not ismax:
		# print('ok2')
		global maxind
		maxind = n



# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

for _ in range(int(input())):
	n = int(input())
	mintrie = dict()
	maxtrie = dict()
	list_of_strings = []
	for i in range(n):
		s = input()
		list_of_strings.append(s)
		makeTrie(s, i+1)
	# print(mintrie, maxtrie)
	# print(sorted(trie.items(), reverse=True))
	# print(max(trie['x']))
	# print(chr(ord('z')+2))

	minind = (getMinInd(mintrie))
	maxind = (getMaxInd(maxtrie))
	q = int(input())
	for i in range(q):
		query = input().split()
		# print(query)
		if query[0] == '1':
			n += 1
			list_of_strings.append(list_of_strings[int(query[1])-1]+query[2])
			addTrie(int(query[1]), query[2])
		elif query[0] == '2':
			# print(minind, list_of_strings[minind-1])
			print(minind)
		else:
			# print(maxind, list_of_strings[maxind-1])
			print(maxind)
		# print(mintrie, maxtrie)
		# print(li)
