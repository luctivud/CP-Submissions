def emirpNumbers(N):
    isPrime = [1] * (N+1)
    sumOfPrimeDivisors = [0] * (N+1)

    for i in range(2, N+1):
        if isPrime[i]:
            for j in range(i, N+1, i):
                isPrime[j] = 0
                sumOfPrimeDivisors[j] += i
    for i in range(2, N+1):
        if i*i > N:
            break
        sumOfPrimeDivisors[i*i] += i
    
    ans = 0
    for i in range(2, N+1):
        ans += (sumOfPrimeDivisors[i] == i)
    return ans

##############################
N = int(input())
print(emirpNumbers(N))