def solve(i, z, prev, mv):
    print(i+1, z, prev, mv)
    if i >= n or mv > k or z < 0:
        return -float('inf')
    if mv == k:
        return li[i]
    if dp[i][prev] == -1:
        if prev != 1 and z > 0 and i > 0:
            dp[i][prev] = li[i] + max(solve(i+1, z, 0, mv+1), solve(i-1, z-1, 1, mv+1))
        else:
            dp[i][prev] = li[i] + solve(i+1, z, 0, mv+1)
    return dp[i][prev]
    
    

for _ in range(int(input())):
    n, k, z = map(int, input().split())
    li = list(map(int, input().split()))
    dp = [[-1]*2 for x in range(n)]
    print(solve(0, z, 0, 0))
    print(dp)
    