class MarblePicking:
	def fewestColors(self, marbles, count):
		from collections import Counter
		from functools import reduce
		c = reduce(Counter.__add__, [Counter(i) for i in marbles])
		ans = 0
		for k, v in sorted(c.items(), key = lambda x: -x[1]):
			if count <= 0:
				break
			count -= v
			ans += 1
		return ans

sol = MarblePicking()
print(sol.fewestColors("AAABBBCCCDDDDE", 4))