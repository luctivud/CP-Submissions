import sys
def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())


from collections import defaultdict, deque


def bfs(source, day):
	visited = [False] * (n+1)
	queue = deque()
	fruits[source] -= min(fruits[source], population[source])
	if (fruits[source] == 0 and ans[source] == -1):
		ans[source] = day
	queue.append(source)
	visited[source] = True
	while(len(queue)):
		# print(queue)
		node = queue.popleft()
		for neighbour in tree[node]:
			if not visited[neighbour] and neighbour in tree:
				queue.append(neighbour)
				visited[neighbour] = True
				fruits[neighbour] -= min(population[source], fruits[neighbour])
				if ans[neighbour] == -1 and fruits[neighbour] == 0:
					ans[neighbour] = day
	return


# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
for _test_ in range(int(input())): 
	n = int(input())
	tree = defaultdict(list)
	for i in range(1, n):
		a, b = get_ints()
		tree[a].append(b)
		tree[b].append(a)

	permutation = get_list()
	population = [0] + get_list()
	fruits = [0] + get_list()
	ans = [-1] * (n+1)

	# print(tree)

	for day, city_to_visit in enumerate(permutation, 1):
		bfs(city_to_visit, day)
		# print()
		# for kelv in tree[city_to_visit]:
		# 	tree[kelv].remove(city_to_visit)
		del tree[city_to_visit]
		# print(tree)
		# print(fruits)

	print(*ans[1:])





