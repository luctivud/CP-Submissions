from bisect import *
def isPalindrome(i):
	return str(i) == str(i)[::-1]
n = int(input())
pal = []
for i in range(1,n+1):
	if isPalindrome(i):
		pal.append(i)
i = n+1
while not isPalindrome(i):
	i += 1
pal.append(i)
se = set(pal)
# print(pal)

ans = 0
while n:
	l = bisect_left(pal, n)
	r = bisect_right(pal, n)
	# print(l, r, pal[l-1], pal[r])
	if isPalindrome(pal[l-1] + pal[r]):
		ans = pal[l-1] + pal[r]
		break
	n -= 1
print(ans)
