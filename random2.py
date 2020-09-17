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
import sys
sys.setrecursionlimit(10**6)
def modInverse(a, m) : 
    m0 = m 
    y = 0
    x = 1
  
    if (m == 1) : 
        return 0
  
    while (a > 1) : 
  
        # q is quotient 
        q = a // m 
  
        t = m 
  
        # m is remainder now, process 
        # same as Euclid's algo 
        m = a % m 
        a = t 
        t = y 
  
        # Update x and y 
        y = x - q * y 
        x = t 
  
  
    # Make x positive 
    if (x < 0) : 
        x = x + m0 
  
    return x 
  
  
# Driver program to test above function 
# a = 3
# m = 11
# print("Modular multiplicative inverse is", 
#        modInverse(a, m)) 
  
# # Driver Program 
# a = 3; m = 11

class Graph: 
      
    # init function to declare class variables 
    def __init__(self,V): 
        self.V = V 
        self.adj = [[] for i in range(V)] 
  
    def DFSUtil(self, temp, v, visited): 
  
        # Mark the current vertex as visited 
        visited[v] = True
  
        # Store the vertex to list 
        temp.append(v) 
  
        # Repeat for all vertices adjacent 
        # to this vertex v 
        for i in self.adj[v]: 
            if visited[i] == False: 
                  
                # Update the list 
                temp = self.DFSUtil(temp, i, visited) 
        return temp 
  
    # method to add an undirected edge 
    def addEdge(self, v, w): 
        self.adj[v].append(w) 
        self.adj[w].append(v) 
    def removeEdge(self, v, w):
        self.adj[v].remove(w) 
        self.adj[w].remove(v)
    # Method to retrieve connected components 
    # in an undirected graph 
    def connectedComponents(self): 
        visited = [] 
        cc = [] 
        for i in range(self.V): 
            visited.append(False) 
        for v in range(self.V): 
            if visited[v] == False: 
                temp = [] 
                cc.append(self.DFSUtil(temp, v, visited)) 
        return cc 
# for _testcases_ in range(int(input())):
n,m = map(int, input().split())
li = []
g = Graph(n)
p = 0; q= 0; mod = 1000000007
for i in range(m):
    temp = list(map(int, input().split()))
    li.append(temp)
    g.addEdge(temp[0]-1, temp[1]-1) 
connected = g.connectedComponents()
for i in range(m):
    edge = li[i]
    g.removeEdge(edge[0]-1, edge[1]-1)
    ccopy = connected.copy()
    cc = g.connectedComponents() 
    for el in ccopy:
        try:
            cc.remove(el)
        except:
            pass
    # print("Following are connected components") 
    # print(cc) 
    if len(cc) == 2:
        # print(cc) 
        q+=1
        if len(cc[0])%2==0 and len(cc[1])%2==0:
            p+=1
    g.addEdge(edge[0]-1, edge[1]-1)
# print(p, q, "check")
if q==0:
    print(0,0)
else:
    if p==0:
        print(0,1)
    # p=1
    else:
        qinv = modInverse(q, mod) 
        print((p * qinv)%mod, ((q-p) * qinv)%mod)


'''
TEST:1
62 79
12 18
42 58
57 15
17 60
46 42
19 41
54 13
51 42
38 36
16 5
52 57
44 48
51 37
12 40
27 12
1 3
36 56
13 1
62 7
31 39
2 6
2 11
40 14
49 47
34 55
58 60
48 43
56 62
38 45
54 37
28 53
57 19
35 19
36 28
33 47
40 50
40 15
32 15
13 16
45 48
34 18
50 9
55 24
39 47
55 12
11 2
7 16
40 6
30 2
9 47
30 60
43 1
61 5
58 61
51 40
42 41
25 47
55 42
7 33
10 28
9 19
11 61
35 36
7 8
40 4
41 25
60 60
62 41
3 28
20 9
16 37
44 23
62 17
59 55
9 40
45 37
2 19
62 29
55 18
'''