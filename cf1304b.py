def isPalindrome(a, b):
    flag = True
    for i in range(len(a)):
        if a[i] != b[len(a)-i-1]:
            flag = False
            break
    return flag

n, m = map(int, input().split())
s = []
startList = []
endList = []
selfList = []
for i in range(n):
    s.append(input().strip())
for i in range(len(s)):
    for j in range(i+1,len(s)):
        if isPalindrome(s[i],s[j]):
            startList.append(s[i])
            endList.append(s[j])
for i in range(len(s)):
    if isPalindrome(s[i],s[i]):
        selfList.append(s[i])
result = ''
for ele in startList:
    result += ele
for ele in selfList:
    result+=ele
    break
for i in range(len(endList)-1, -1, -1):
    result += endList[i]
print(len(result))
print(result)