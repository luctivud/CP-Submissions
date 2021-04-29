class Pancakes(object):
	def makePancakes(self, N, P):
		ans = []
		import collections
		queue = collections.deque()
		for i in range(N):
			queue.append(chr(ord('A')+i))
		# print(queue)

		while (len(queue)):
			res = ['-' for x in range(P)]
			nxt = []
			for i in range(P):
				if len(queue):
					ob = queue.popleft()
					if 'A' <= ob <= 'Z':
						nxt.append(ob.lower())
					res[i] = ob
				else:
					break
			for i in nxt:
				queue.append(i)
			ans.append("".join(res))

		return ans

ob = Pancakes()
print(ob.makePancakes(4, 3))
