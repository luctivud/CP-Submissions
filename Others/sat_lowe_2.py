#   J A I  S H R E E  R A M   #


# import math, sys, collections, functools, time, itertools;

# sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

import collections
mod = int(1e9) + 7
def dfs(node, par, color, adj, dp):
    # print(dp);
    if dp[node][color] != -1:
        return dp[node][color]
    dp[node][color] = 0
    leaf = 0
    for i in adj[node]:
        if i != par:
            dp[node][color] += dfs(i, node, color, adj, dp)
            dp[node][color] %= mod
            if color == 1:
                dp[node][color] += dfs(i, node, color ^ 1, adj, dp)
                dp[node][color] %= mod
            leaf += 1
    if leaf == 0:
        dp[node][color] = 1
    return dp[node][color]

n = int(input())
st = int(input())
adj = collections.defaultdict(list)
for x in range(n-1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

dp = [[-1 for x in range(2)] for y in range(n+1)]
dp[st][0] = 0
print(dfs(st, 0, 1, adj, dp))

