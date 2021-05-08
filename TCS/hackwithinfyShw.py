n = int(input())
circumference = int(input())
pos , gold = [], []

for i in range(n):
	pos.append(int(input()))
for i in range(n):
	gold.append(int(input()))


ANS = 0

ans, netGold = 0, 0
front_max, back_max = [], []
for i in range(n):
	netGold += gold[i]
	ans = max(ans, netGold - pos[i])
	front_max.append(ans)

ANS = max(ANS, ans)

pos = [circumference - i for i in pos]
pos = pos[::-1]
gold = gold[::-1]
netGold = ans = 0
for i in range(n):
	netGold += gold[i]
	# print(netGold, pos[i])
	ans = max(ans, netGold - pos[i])
	back_max.append(ans)

# print(front_max)
# print(back_max)

netGold = ans = 0
for i in range(n-1):
	netGold += gold[i]
	ans = netGold - pos[i] + front_max[n-i-2] - pos[i] 
	ANS = max(ans, ANS)

pos = [circumference - i for i in pos]
pos = pos[::-1]
gold = gold[::-1]
back_max = back_max[::-1]
netGold = ans = 0
for i in range(n-1):
	netGold += gold[i]
	# print(netGold-2*pos[i])
	ans = netGold - pos[i] + back_max[i+1] - pos[i] 
	ANS = max(ans, ANS)

print(ANS)