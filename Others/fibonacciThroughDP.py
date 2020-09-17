dp = [0, 1]
def fibo(n):
    try:
        return dp[n]
    except:
        dp[n] = fibo(n-1)+ fibo(n-2)
        return dp[n]

n = 5
print(fibo(n))