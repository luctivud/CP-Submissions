class Graph():
    def __init__(self, graph):
        self.graph = graph
        self.n = len(graph)
    
    def bipartiteMatch(self, i,  matching, visited):
        for vertex in range(self.n):
            if self.graph[i][vertex] and not visited[vertex]:
                visited[vertex] = True
                if matching[vertex] == -1 or self.bipartiteMatch(matching[vertex], matching, visited): 
                    matchR[v] = i
                    return True
        return False

    def maxBipartite(self):
        matching = [-1] * self.n
        res = 0 
        for i in range(self.n): 
            visited = [False] * self.n 
            if self.bipartiteMatch(i, matching, visited):
                res += 1
        return matching