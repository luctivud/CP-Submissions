def computerTime(cls, input3, input2, input1):
    ans = []
    curr = 0
    for i in input2:
        if (curr + i[1] - i[0] + 1 <= input3):
            curr += i[1] - i[0] + 1
            ans.append(i[0])
        else:
            curr = 0
    if (len(ans) == 0):
        ans = [-1]
    return ans


print(computerTime(0, 4, [[1, 2], [2, 3], [3, 4], [4, 5]], 3))
print(computerTime(0, 2, [[1, 4], [6, 9]], 3))