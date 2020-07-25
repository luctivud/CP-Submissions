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
    if gas not in dp[i]:
        if li[i] == 0:
            dp[i][gas] = solve(i+1, cost, gas-1)
        else:
            dp[i][gas] = min(solve(i+1, cost, gas-1), solve(i+1, cost+li[i], m-1))
    return dp[i][gas]


from collections import defaultdict
Test = int(input())
INF = float('inf')
for T in range(1, Test+1):
    print("Case #{}:".format(T), end = " ")
    n, m = map(int, input().split())
    li = []
    for _ in range(n):
        li.append(int(input()))

    dp = [dict() for x in range(n)]

    # count = 0
    ans = solve(0, 0, m)
    # print(dp)
    # print(count)
    if ans == INF:
        print(-1)
    else:
        print(ans)

