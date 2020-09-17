'''     ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█  
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     '''


# [cf-1382-b.py] => [21-07-2020 @ 20:22:48] 
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
    li = get_list()
    if n == 1:
        print("First")
    else:
        pos = -1
        for i in range(n):
            if li[i] == 1:
                pos = i
            else:
                break
        # printsp(pos)
        if pos == -1:
            print("First")
        elif pos == n-1:
            if n & 1:
                print("First")
            else:
                print("Second")
        else:
            if pos & 1:
                print("First")
            else:
                print("Second")
        # if i == n:




S34p = time.time()
# print("Time Elapsed: {}".format(float(S34p-S34t)))
''' ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                             SHREE RAM JAI RAM, JAI JAI RAM 
                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'''
