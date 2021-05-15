class  LongestPalindrome(object):
	def longestLength(self, s):
		n = len(s)
		ans = 1
		for i in range(n):
			for j in range(i+1, n+1):
				if s[i:j] == s[i:j][::-1]:
					ans = max(ans, j-i)
		return ans


obj = LongestPalindrome()
print(obj.longestLength("ABAA"))