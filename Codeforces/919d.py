#   J A I  S H R E E  R A M   #


import math, sys, collections, functools, time, itertools;

# sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")
input=sys.stdin.readline


d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>





def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    n, m = Read_Ints()
    adj = collections.defaultdict(list)
    indeg = [0 for x in range(n)]
    s = input();

    for i in range(m):
        a, b = Read_Ints()
        adj[a-1].append(b-1);
        indeg[b-1] += 1;

    que = collections.deque();

    ans = 0; 
    dp = [[0 for x in range(26)] for xx in range(n)]
    # for j in range(26):

    for i in range(n):
        if indeg[i] == 0:
            que.append(i)
    cnt = 0
    while (len(que)):
        node = que.popleft()
        dp[node][ord(s[node])-ord('a')] += 1
        for i in adj[node]:
            for j in range(26):
                dp[i][j] = max(dp[node][j], dp[i][j])
            indeg[i] -= 1
            if indeg[i] == 0:
                que.append(i)
        cnt += 1
        if cnt > n:
            break
    # print(cnt)
    # print(dp)
    ans = max([max(dp[i]) for i in range(n)])
    print(ans if cnt == n else -1)
    






_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

