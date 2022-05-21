def findMaxMoney(cost, x):
    res, mod = 0, int(1e9)+7
    n = len(cost)
    for i in range(n-1, -1, -1):
        if cost[i] <= x:
            x -= cost[i]
            res += pow(2, i, mod)
            res %= mod
    return res



n = int(input())
cost = []
for i in range(n):
    cost.append(int(input()))
x = int(input())

print(findMaxMoney(cost, x))

