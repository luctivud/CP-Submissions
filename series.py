ser = [1, 2, 6]
def getSer(n):
    try:
        return ser[n]
    except:
        ans = ((getSer(n-1)+getSer(n-2))*2)%1000000007
        ser.append(ans)
        return ser[n]
for __ in range(int(input())):
    n= int(input())
    print(getSer(n)%1000000007)