class HIndex(object):
	def cheat(self, realCitations, budget, citationPrice):
		num = budget // citationPrice
		n = len(realCitations)
		realCitations = list(realCitations)
		realCitations.sort(reverse = True)
		# print(realCitations)
		l, r = 0, n
		ans = 0
		while l <= r:
			mid = (l + r) >> 1
			extra = num
			for i in range(mid):
				# print(mid, i, extra, realCitations[i])
				if realCitations[i] < mid:
					extra -= (mid - realCitations[i])
			# print(mid, extra)
			if extra >= 0:
				ans = max(ans, mid)
				l = mid + 1
			else:
				r = mid - 1
		return ans


Hind = HIndex()
print(Hind.cheat((25, 3, 5, 3, 8, 0), 447, 1000))