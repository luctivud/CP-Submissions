#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#   '          .       ,     神 | 光      .     '        .      , #
#     .      '        Udit Gupta @luctivud         ,              #
#  ,    '   ELDIOS | LIGHT | GREED | CIPHER | XAYN | KIRA '    .  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
                ##     ##   ######   # #  ######
                ##     ##   ##  ##   ###    ##
                ##     ##   ##   #   # #    ##
                ###### ##   ######   # #    ##
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~| WORSHIPPER OF GREED |~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
import sys
import math as mt
# sys.setrecursionlimit(10**6)
def printsp(*args): return print(*args, end=" ")
def printchk(*args): return print(*args, end="/tst, ")
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()
#########################################################################
MOD = int(1e9+7); BABYMOD = 998244353;
from collections import defaultdict 

# ############################################################ ##########
class Graph: 
    def __init__(self,vertices): 
        self.V= vertices  
        self.graph = defaultdict(list)  
    def addEdge(self,u,v): 
        self.graph[u].append(v) 
    def getPathsUtil(self, u, d, visited, path, ansli): 
        visited[u]= True
        path.append(u) 
        if u ==d: 
            pathcopy = path.copy()
            ansli.append(pathcopy)
        else: 
            for i in self.graph[u]: 
                if visited[i]==False: 
                    ansli = self.getPathsUtil(i, d, visited, path, ansli) 
        path.pop() 
        visited[u]= False
        return ansli
    def getPaths(self, u, v, ansli): 
        visited =[False]*(self.V) 
        path = [] 
        ansli = self.getPathsUtil(u, v, visited, path, ansli) 
        return ansli
# ###############################################################################
def getAnsForPath(path, ind, li, days, dp):
    print("for day", days, "index", ind)
    try:
        if dp[ind][days] != -1:
            return dp[ind][days]
    except: pass
    if days<0:
        return 0
    if days==0:
        return 1
    if ind >= len(path): return 0
    # print(ind, days)
    if days==1:
        ans = 0
        for i in range(ind, len(path)):
            ans+=li[path[i]]
        return ans
    if days>1:
        ans = 0
        for i in range(ind, len(path)):
            for j in range(days, -1, -1):
                wow = pow(li[path[i]], j) * getAnsForPath(path, i+1, li, days-j, dp)
                # dp[i][j] = wow
                print(wow, "wow", ind, days)
                ans+=wow
                # if wow == 0:
                #     return ans
        return ans
        # for i in range(1, days+1):
        #     for j in range(ind,len(path)):
        #         ans+= pow(li[path[i]], i) * getAnsForPath(path, j+i, li, days-i)
        #     # printsp(ans,"|")

# ###############################################################################
# for _testcases_ in range(int(input())):
n, m, q = get_ints()
li = get_array()
graph = Graph(n)
for _ in range(m):
    u, v = get_ints()
    graph.addEdge(u-1, v-1)
# print(adj_list)
queries = get_array()
ansli = []
ansli = graph.getPaths(0, n-1, ansli)
# print(ansli)
for days in queries:
    ans = 0
    for path in ansli:
        dp = [[-1]*n for x in range(days)]
        ans += getAnsForPath(path, 0, li, days-len(path)+1, dp)
    print(ans)
'''
The above code used is taken from geeksforgeeks.org
Please do not plagiarise.
4 4 3
2 6 6 7
1 2
1 3
2 4
3 4
1 2 3
'''