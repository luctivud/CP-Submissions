## Read input as specified in the question.
## Print output as specified in the question.
import sys
sys.setrecursionlimit(int(1e6))
input = sys.stdin.readline

def dfs(adj_list, visited, i, visited_stack):
  visited[i] = True
  for j in range(len(adj_list[i])):
    if(not visited[adj_list[i][j]]):
      dfs(adj_list, visited, adj_list[i][j], visited_stack)
  visited_stack.append(i)

def dfs2(adj_list, visited, i):
  visited[i] = True
  for j in range(len(adj_list[i])):
    if(not visited[adj_list[i][j]]):
      dfs(adj_list, visited, adj_list[i][j], visited_stack)

t = int(input())
while(t != 0):
  no_input = [int(x) for x in input().split()]
  n = no_input[0]
  d = no_input[1]
  adj_list = []
  adj_list_T = []
  for i in range(n + 1):
    adj_list.append([])
    adj_list_T.append([])

  
  for i in range(d):
    edges = [int(x) for x in input().split()]
    start = edges[0]
    end = edges[1]
    adj_list[start].append(end)
    adj_list_T[end].append(start)
  
  visited_stack = []
  visited = [False] * (n + 1)
  for i in range(1, n + 1):
    if(not visited[i]):
      dfs(adj_list, visited, i, visited_stack)

  count = 0
  visited = [False] * (n + 1)
  while(len(visited_stack)):
    each_element = visited_stack.pop()
    if(not visited[each_element]):
      count += 1
      dfs2(adj_list, visited, each_element)
  print(count)

  t -= 1