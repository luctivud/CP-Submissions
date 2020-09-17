for _ in range(int(input())):
    n = int(input())
    if n == 6:
        ans = 999999999
        mx = -1
        for i in range(100000, 1000000):
            # print("ok")
            temp = ''
            j = i
            while i>0:
                temp = bin(i % 10)[2:] + temp
                i //= 10
            # print(j, temp[:-n], mx)
            temp = temp[:-n]
            if temp != '':
                temp = int(temp, 2)
                if temp > mx:
                    mx = temp
                    ans = j 
        print(ans)
