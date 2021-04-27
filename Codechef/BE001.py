#				 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/					 #


from math import *;   		from collections import *
import sys;   		from functools import reduce
import time;   		from itertools import groupby

# sys.setrecursionlimit(10**6)

# def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (-1, -0)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]



# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

def getNcR(n, r):
  p = 1
  k = 1
  if (n - r < r):
    r = n - r
  if (r != 0):
    while (r):
      p *= n
      k *= r
      m = gcd(p, k)
      p //= m
      k //= m
      n -= 1
      r -= 1
  else:
    p = 1
  return p

for _test_ in range(int(input())): 
	n, a, b = get_ints()
	print(getNcR(n, a) * getNcR(n, b))





