# li = list(map(int, input().split()))
n, m = map(int, input().split())
matr = []
for i in range(n):
	matr.append(list(input().split()))
for i in range(n):
	for j in range(m):
		if matr[i][j] == "snuke":
			print(chr(ord('A')+j)+str(i+1))
			break
# print(chr(ord('A')+ind[1])+str(ind[0]))