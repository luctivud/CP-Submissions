'''     J A I ~ S H R E E ~ R A M     '''

# Title: cc-CKOJ20C.py
# created on: 20-07-2020 at 21:32:52
# Creator & Template : Udit Gupta "@luctivud"
# https://github.com/luctivud
# https://www.linkedin.com/in/udit-gupta-1b7863135/


import math; from collections import *
import sys; from functools import reduce
from itertools import groupby

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

# Custom input output is now piped through terminal commands.
prime = [True] * MAXN_EYEPATCH
prime[1] = prime[0] = False
for i in range(2, MAXN_EYEPATCH):
    if prime[i]:
        for j in range(2*i, MAXN_EYEPATCH, i):
            prime[j] = False


def solve(node):
    # print(node)
    if prime[li[node]]:
        dp[node][0] += 1
    else:
        dp[node][1] += 1
    visited.add(node)
    suuki = saaku = 0
    maxwel = 0
    for zen in tree[node]:
        if zen not in visited:
            t1, t2, _ = solve(zen)
            suuki += t1
            saaku += t2
            # print(t1, t2)
    diff = dp[node][0] - dp[node][1]
    print(node, diff, suuki, saaku)
    if abs(diff + suuki) > abs(diff + saaku):
        dp[node][0] += suuki
    else:
        dp[node][1] += saaku
    maxwel = max(maxwel, abs(dp[node][0]-dp[node][1]))
    dp[node][2] = maxwel
    return dp[node]


# for _testcases_ in range(int(input())): 
n = int(input())
tree = defaultdict(list)
li = [0] + get_list()
for _ in range(n-1):
    a, b = get_ints()
    tree[a].append(b)
    tree[b].append(a)
# print(tree)
dp = [[0] * 3 for _ in range(n+1)]
visited = set()
solve(1)
print(dp)



'''
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here, otherwise.
'''
