import collections

d4i = [0, 0, 1, -1]
d4j = [1, -1, 0, 0]

for T in range(int(input())):
    n, m = map(int, input().split())
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())
    matr = [[0 for x in range(m)] for y in range(n)]
    matr[x1-1][y1-1] = 1
    matr[x2-1][y2-1] = 2
    cntUsed = collections.defaultdict(int)
    cntUsed[1] = 1
    cntUsed[2] = 1
    for i in range(n):
        for j in range(m):
            if matr[i][j] != 0:
                continue
            mex = set([1, 2, 3, 4, 5])
            for x in range(4):
                newi = i + d4i[x]
                newj = j + d4j[x]
                if newi >= 0 and newi < n and newj >= 0 and newj < m:
                    if matr[newi][newj] in mex:
                        mex.remove(matr[newi][newj])
            res, resCount = 0, -1
            # print(mex)
            for mexElem in mex:
                if cntUsed[mexElem] > resCount:
                    resCount = cntUsed[mexElem]
                    res = mexElem
            matr[i][j] = res

    for i in matr:
        print(*i)