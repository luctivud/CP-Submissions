def SumNumbers(m, n):
    lo = (m + 14) // 15
    hi = (n // 15)
    cnt = (hi - lo) + 1
    print(lo, hi)
    return (cnt // 2) * 15 * (hi + lo)

n, m = map(int, input().split())
print(SumNumbers(n, m))