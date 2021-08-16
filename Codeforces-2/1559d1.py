import math, sys, collections, functools, time, itertools;

# sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

class DisjSet:
    def __init__(self, n):
        self.rank = [1] * n
        self.parent = [i for i in range(n)]
  
    def find(self, x):
        if (self.parent[x] != x):
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def Union(self, x, y):
        xset = self.find(x)
        yset = self.find(y)
        if xset == yset:
            return
        if self.rank[xset] < self.rank[yset]:
            self.parent[xset] = yset
  
        elif self.rank[xset] > self.rank[yset]:
            self.parent[yset] = xset
        else:
            self.parent[yset] = xset
            self.rank[xset] = self.rank[xset] + 1



def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    n, m1, m2 = Read_Ints()
    G1 = DisjSet(n)
    G2 = DisjSet(n)

    for x in range(m1):
        a, b = Read_Ints()
        G1.Union(a-1, b-1)

    for x in range(m2):
        a, b = Read_Ints()
        G2.Union(a-1, b-1)

    ans = []
    for i in range(n):
        for j in range(i+1, n):
            if G1.find(i) != G1.find(j) and G2.find(i) != G2.find(j):
                G1.Union(i, j)
                G2.Union(i, j)
                ans.append([i+1, j+1])

    print(len(ans))
    for i in ans:
        print(*i)






_T0T4 = 1;
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)



