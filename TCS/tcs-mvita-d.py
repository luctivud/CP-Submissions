import sys; import math; from collections import *

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

n = int(input())
r1, r2 = get_ints()
total = int(input())
mon = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
d = defaultdict(lambda : 0)
for i, m in enumerate(mon):
    for j in range(1, m+1):
        this = (6-i-1)**2 + abs(j-15)
        d[this] += 1
ans = n
for i in range(n+1):
    tv = i; ch = n-i
    rev = 0
    for k, v in d.items():
        getcheap = min(k, ch)
        k -= getcheap
        gettv = min(k, tv)
        rev += v *(getcheap*r2 + gettv*r1)
    if rev >= total:
        ans = i
        break
print(ans)

