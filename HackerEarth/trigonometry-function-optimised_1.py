li = [0, 2, 10]

prev1, prev2, mod = 1, 2, int(1e190)+21
for i in range(2,100):
	num1 = (4 * prev2) - (7 * prev1)
	num3 = (i * pow(4, i, mod)) % mod
	ans = (2 * num1 + num3 + mod) % mod
	# print("prev", prev1, prev2)
	# print(num1, num3)
	li.append((li[-1]+ans) % mod)
	prev1, prev2 = prev2, num1

while len(set(li)) > 1:
	print(li)
	li2 = []
	for i in range(len(li)-1):
		li2.append(li[i+1]-li[i])
	li = li2

# t = int(input())
# while t:
# 	t -= 1
# 	l, r = map(int, input().split())
# 	print(li[r+1] - li[l])