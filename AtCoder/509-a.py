n = int(input())
matr = [[0]*n for i in range(n)]
for i in range(n):
    matr[i][0] = 1
    matr[0][i] = 1
for i in range(1, n):
    for j in range(1, n):
        matr[i][j] = matr[i-1][j] + matr[i][j-1]
print(matr[n-1][n-1])