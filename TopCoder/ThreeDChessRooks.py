class DisjSet(object):
	def __init__(self, n):
		self.rank = [1] * n
		self.parent = [i for i in range(n)]

	def find(self, x):
		if (self.parent[x] != x):
			self.parent[x] = self.find(self.parent[x])
			# print(self.parent[x])
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
  

class ThreeDChessRooks(object):
	def count(self, C, R, XP, YP, ZP, seed):
		L = len(XP)
		X = [0] * (R)
		Y = [0] * (R)
		Z = [0] * (R)
		for i in range(L):
			X[i] = XP[i]
			Y[i] = YP[i]
			Z[i] = ZP[i]

		state = seed
		modu = 2 ** 31
		for i in range(L, R):
			state = (state * 1103515245 + 12345) % modu
			X[i] = state % C
			state = (state * 1103515245 + 12345) % modu
			Y[i] = state % C
			state = (state * 1103515245 + 12345) % modu
			Z[i] = state % C		
		
		points = set()
		for i in range(R):
			points.add((X[i], Y[i], Z[i]))

		dj = DisjSet(R)

		import collections
		dx = collections.defaultdict(set)
		dy = collections.defaultdict(set)
		dz = collections.defaultdict(set)

		for ind, point in enumerate(points):
			(x, y, z) = point
			dx[x].add(ind)
			dy[y].add(ind)
			dz[z].add(ind)

		# print(dx, dy, dz)
		ans = 0
		for ke, va in dx.items():
			se2 = set()
			for ii in va:
				se2.add(dj.find(ii))
			sz = len(se2)
			# print(sz, se2)
			ans += (sz * (sz - 1))
			for ii in va:
				zz = ii
				break
			for ii in va:
				dj.Union(ii, zz)

		for ke, va in dy.items():
			se2 = set()
			for ii in va:
				se2.add(dj.find(ii))
			sz = len(se2)
			ans += (sz * (sz - 1))
			for ii in va:
				zz = ii
				break
			for ii in va:
				dj.Union(ii, zz)

		for ke, va in dz.items():
			se2 = set()
			for ii in va:
				se2.add(dj.find(ii))
			sz = len(se2)
			ans += (sz * (sz - 1))
			for ii in va:
				zz = ii
				break
			for ii in va:
				dj.Union(ii, zz)
		return ans


obj = ThreeDChessRooks()
print(obj.count(99,8,[47, 48, 49, 50, 50, 51, 52, 53],[12, 12, 12, 12, 12, 12, 12, 12],[12, 12, 12, 12, 12, 12, 12, 12],111))