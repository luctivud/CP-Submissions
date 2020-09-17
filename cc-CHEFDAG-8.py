#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# Udit Gupta @luctivud  神 | LIGHT | GREED | CIPHER | XAYN
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
                ##     ##   ######   # #  ######
                ##     ##   ##  ##   ###    ##
                ##     ##   ##   #   # #    ##
                ###### ##   ######   # #    ##
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#                   | WORSHIPPER OF GREED | 
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
class Graph: 
    def __init__(self,graph): 
        self.graph = graph  
        self.taker = len(graph) 
        self.giver = len(graph[0]) 
    def bpm(self, u, resultantList, visitedd): 
        for v in range(self.giver): 
            if self.graph[u][v] and visitedd[v] == False: 
                visitedd[v] = True 
                if resultantList[v] == -1 or self.bpm(resultantList[v], resultantList, visitedd): 
                    resultantList[v] = u 
                    return True
        return False
    def maxBPM(self): 
        resultantList = [-1] * self.giver 
        result = 0 
        for i in range(self.taker): 
            visitedd = [False] * self.giver 
            if self.bpm(i, resultantList, visitedd): 
                result += 1
        return resultantList 
# #########################################################################
for _test_ in range(int(input())):
    n, k = map(int, input().split())
    d = {}
    for i in range(1,n+1):
        for j in range (1,n+1):
            if j!=i:
                try:
                    d[i].add(j)
                except:
                    d[i] = set()
                    d[i].add(j)
    for ki in range(k):
        li = list(map(int, input().split()))
        for i in range (n):
            for j in range(i):
                try:
                    d[li[i]].remove(li[j])
                except:
                    pass
    revNode = {}
    for k, v in d.items():
        for val in v:
            try:
                revNode[val].add(k)
            except:
                revNode[val] = set()
                revNode[val].add(k)
    # ###############--CREATE--ALL--POSSIBLE--###################
    # bpGraph =[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[1,1,1,0,0,0],[1,0,0,0,0,0],[0,1,1,0,0,0]] 
    permutli = [[0]*n for x in range(n)]
    for k, v in revNode.items():
        for el in v:
            permutli[k-1][el-1] = 1
    # print(permutli)
    resGraph = Graph(permutli) 
    ansli = resGraph.maxBPM()
    # print () 
    for i in range(n):
        ansli[i]+=1
    count = 0
    for i in range(1, n+1):
        if i not in ansli:
            count += 1
    print(count)
    for el in ansli:
        print(el, end=" ")
    print()
