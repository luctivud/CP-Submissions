n, m = map(int, input().split())
matr = []
for i in range(n):
    matr.append(list(input()))
lrud = [[[0] * 4 for x in range(m)] for y in range(n)]
for i in range(n):
    num = 0
    for j in range(m):
        lrud[i][j][0] = num
        if matr[i][j] == '*':
            num += 1

for i in range(n):
    num = 0
    for j in range(m-1, -1, -1):
        lrud[i][j][1] = num
        if matr[i][j] == '*':
            num += 1


# matr = list(zip(*matr))
# print(lrud)
matr = [[matr[j][i] for j in range(n)] for i in range(m)]
# print(matr)
for i in range(n):
    num = 0
    for j in range(m):
        lrud[i][j][2] = num
        if matr[j][i] == '*':
            num += 1

for i in range(n):
    num = 0
    for j in range(m-1, -1, -1):
        lrud[i][j][3] = num
        if matr[j][i] == '*':
            num += 1

# print(lrud)
for i in lrud:
    for j in i:
        print(j, end=" ")
    print()

matr = [[matr[j][i] for j in range(m)] for i in range(n)]

ans = 0
for i in range(n):
    for j in range(m):
        if matr[i][j] == '*':
            a, b, c, d = lrud[i][j]
            ans += (c*a) + (d*a) + (c*b) + (d*b)
print(ans)