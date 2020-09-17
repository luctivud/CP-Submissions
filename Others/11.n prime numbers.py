N = 100
i, j, flag = 0, 0, False
for i in range(1, N + 1, 1): 
    if (i == 1 or i == 0): 
        continue
    flag = True
    for j in range(2, ((i // 2) + 1), 1): 
        if (i % j == 0): 
            flag = 0
            break
    if (flag == 1): 
        print(i, end = " ")