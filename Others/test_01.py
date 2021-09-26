n, m = map(int, input().split())
matr = []
for i in range(n):
    matr.append(input())
    
# print(matr)
    
validRows = set()
validCols = set()

for i in range(n):
    ok = False
    for j in range(m):
        if matr[i][j] == '#':
            ok = True
    if ok:
        validRows.add(i)
        
for i in range(m):
    ok = False
    for j in range(n):
        if matr[j][i] == '#':
            ok = True
    if ok:
        validCols.add(i)
        
# print(validRows)
# print(validCols)

for i in range(n):
    ok = False
    for j in range(m):
        if i in validRows and j in validCols:
            ok = True
            print(matr[i][j], end = "")
    if ok:
        print()
            

        