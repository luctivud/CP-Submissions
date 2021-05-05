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


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (-1, -0)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]



# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

def totient(n) :          # n - unsigned int
    result = 1
    p = 2                 #prime numbers - 'iterator'
    while p**2 <= n :
        if(n%p == 0) :    # * (p-1)
            result *= (p-1)
            n //= p
        while(n%p == 0) : # * p^(k-1)
            result *=  p
            n //= p
        p += 1
    if n != 1 :
        result *= (n-1)
    return result       


# for _test_ in range(int(input())): 
n, m = get_ints()
li = get_list()
li = [1] + li
n *= 2;

tot = [m]
for i in range(n-1):
	tot.append(totient(tot[-1]))
tot = tot[::-1]
# print(tot)
# print(li)
ans = []
for i in range(1, n+1):
	res = 1;
	for j in range(i):
		res = pow(li[j+1], res, tot[n-i+j])
		# print("oh", i, j, li[j+1], res, tot[n-i+j])
	ans.append(res)

print(*ans)




