'''     J A I ~ S H R E E ~ R A M     '''

# Title: kickstart-d-subtask-1-specific.py
# dated: 12-07-2020 12:03:27
# Creator & Template by : Udit Gupta @luctivud


import math; from collections import *
import sys; from functools import reduce

# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def get_string(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

DIRECTIONS = [[0, 1], [0, -1], [1, 0], [1, -1]] #up, down, right, left
NEIGHBOURS = [(i, j) for i in range(-1, 2) for j in range(-1, 2) if (i!=0 or j!=0)]

OrdUnicode_a = ord('a'); OrdUnicode_A = ord('A')
CAPS_ALPHABETS = {chr(i+OrdUnicode_A) : i for i in range(26)}
SMOL_ALPHABETS = {chr(i+OrdUnicode_a) : i for i in range(26)}

MOD_JOHAN = int(1e9)+7; MOD_LIGHT = 998244353; INFINITY = float('inf')
MAXN_EYEPATCH = int(1e5)+1; MAXN_FULLMETAL = 501

# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")

for _testcases_ in range(int(input())):
    n, q = get_ints()
    printsp("Case #{}:".format(_testcases_+1))
    doors = [INFINITY] + get_list() + [INFINITY]
    # print(doors)
    for i in range(q):
        s, k = get_ints()
        thisroom = s
        prev = s-1
        nxt = s
        while k > 1:
            if (doors[prev] < doors[nxt]) :
                thisroom = prev
                prev -= 1
            elif (doors[nxt] < doors[prev]) :
                nxt += 1
                thisroom = nxt
            k -= 1
            # printsp(thisroom)
        printsp(thisroom)
        # print()
    print()





'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
'''
