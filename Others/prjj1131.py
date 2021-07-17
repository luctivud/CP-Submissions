import heapq
n = int(input())
li2 = list(map(int, input().split()))
maxAns = -float('inf')
res = []
for i in range(1, n-1):
    li = li2[i:].copy()
    sumOf = sum(li)
    heapq.heapify(li)
    sumOf -= heapq.heappop(li)
    if (sumOf / len(li) > maxAns):
        maxAns = sumOf / len(li)
        res = [i]
    elif (sumOf / len(li) == maxAns):
        res.append(i)
    # print(sumOf, res, maxAns)
print(*res)