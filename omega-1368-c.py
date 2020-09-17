n = int(input())
print(7*n+8)
import sys; sys.stdout = open('output.txt', 'w')
flag = False
matr = [[1,1,1,0,0],[1,0,1,0,0],[1,1,1,1,1],[0,0,1,0,1],[0,0,1,1,1]]
fac = 0
for i in range(5):
    for j in range(5):
        if i == 2 and j == 0:
            if not flag:
                print(i, j)
                flag = True
        else:
            if matr[i][j]:
                print(i, j+fac)
fac += 4
n -= 1
while n>0:
    if n % 2:
        for i in range(2):
            for j in range(2):
                if i == 2 and j == 0:
                    if not flag:
                        print(i, j)
                        flag = True
                else:
                    if matr[i][j]:
                        print(i, j+fac)
    else:
        for i in range(5):
            for j in range(5):
                if i == 2 and j == 0:
                    if not flag:
                        print(i, j)
                        flag = True
                else:
                    if matr[i][j]:
                        print(i, j+fac)

    n -= 2
    fac += 4