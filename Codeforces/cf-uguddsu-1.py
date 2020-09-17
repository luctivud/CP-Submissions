'''     ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█  
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     '''


# [cf-1382-c.py] => [21-07-2020 @ 20:28:34] 
# Author & Template by : Udit "luctivud" Gupta
# https://www.linkedin.com/in/udit-gupta-1b7863135/


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
for _testcases_ in range(int(input())): 
    n = int(input())
    a = list(input())
    b = list(input())
    j = n-1
    moves = 0
    ans = []
    while j >= 0:
        if a[j] != b[j]:
            if a[0] == b[j]:
                moves += 1
                if a[0] == '1':
                    a[0] = '0'
                else:
                    a[0] = '1'
                ans.append(1)
            for i in range((j+2)//2):
                if i == j-i:
                    if a[i] == '1':
                        a[i] = '0'
                    else:
                        a[i] = '1'
                else:
                    a[i], a[j-i] = a[j-i], a[i]
                    if a[i] == '0':
                        a[i] = '1'
                    else:
                        a[i] = '0'
                    if a[j-i] ==  '0':
                        a[j-i] = '1'
                    else:
                        a[j-i] = '0'
            moves += 1
            ans.append(j+1)
        j -= 1
    print(moves, *ans)




S34p = time.time()
# print("Time Elapsed: {}".format(float(S34p-S34t)))
''' ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                             SHREE RAM JAI RAM, JAI JAI RAM 
                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'''
