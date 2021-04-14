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


# Python program for insert and search
# operation in a Trie

class TrieNode:
	def __init__(self):
		self.children = [None]*2
		self.isEndOfWord = False

class Trie:
	
	# Trie data structure class
	def __init__(self):
		self.root = self.getNode()
		self.ans = 0

	def getNode(self):
		return TrieNode()

	def _charToIndex(self,ch):
		return ord(ch)-ord('0')


	def insert(self, key):
		pCrawl = self.root
		length = len(key)
		for level in range(length):
			index = self._charToIndex(key[level])
			if not pCrawl.children[index]:
				pCrawl.children[index] = self.getNode()
				self.ans += 1
			pCrawl = pCrawl.children[index]
		pCrawl.isEndOfWord = True

	# def search(self, key):
		
	# 	# Search key in the trie
	# 	# Returns true if key presents
	# 	# in trie, else false
	# 	pCrawl = self.root
	# 	length = len(key)
	# 	for level in range(length):
	# 		index = self._charToIndex(key[level])
	# 		if not pCrawl.children[index]:
	# 			return False
	# 		pCrawl = pCrawl.children[index]

	# 	return pCrawl != None and pCrawl.isEndOfWord



# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

for _test_ in range(int(input())): 
	n, m = get_ints()
	t = Trie()
	for i in range(n):
		t.insert(input())
	print(t.ans)




