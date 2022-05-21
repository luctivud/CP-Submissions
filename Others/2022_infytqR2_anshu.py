n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))

def maxTime(n, arr):
    arr.sort(key = lambda x : x[2])
    visitors = set()
    ans = 0
    for a, b, c in arr:
        if a == 0:
            if b in visitors:
                visitors.remove(b)
        else:
            visitors.add(b)
        ans = max(ans, len(visitors))
    return ans