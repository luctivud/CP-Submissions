class CubeTower(object):
	def difference(self, h, n):
		a1, a2 = [h//n] * n, [1] * n
		a2[n-1] = (h-n+1)
		extra = h - ((h // n) * n)
		for i in range(extra):
			a1[i] += 1
		ans = 0
		# print(a1)
		# print(a2)
		for i in range(n):
			ans += (a2[i]**3 - a1[i]**3)
		return ans


obj = CubeTower()		
print(obj.difference(4, 2))