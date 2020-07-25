def solve(i, cost, gas):
    # print(i, cost, gas)
    # global count
    # count += 1
    if i == n-1 and gas >= 0:
        return cost
    if gas == 0 and li[i] == 0:
        return INF
    if gas < 0:
        return INF
    if li[i] == 0:
        if dp[i] == -1:
            dp[i] = solve(i+1, cost, gas-1)
        else:
            dp[i] = solve(i+1, cost, gas-1)
    else:
        if dp[i] == -1:
            dp[i] = min(solve(i+1, cost, gas-1), solve(i+1, cost+li[i], m-1))
        else: 
            dp[i] = min(dp[i], solve(i+1, cost, gas-1), solve(i+1, cost+li[i], m-1))
    return dp[i]


Test = int(input())
INF = float('inf')
for T in range(1, Test+1):
    print("Case #{}:".format(T), end = " ")
    n, m = map(int, input().split())
    li = []
    for _ in range(n):
        li.append(int(input()))

    dp = [-1 for x in range(n)]

    # count = 0
    ans = solve(0, 0, m)
    # print(count)
    if ans == INF:
        print(-1)
    else:
        print(ans)

