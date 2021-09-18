def countPoints(circle1, circle2):
    def checkIn(x, y, circle):
        x1 = (x - circle[0])
        y1 = (y - circle[1])
        return ((x1 * x1) + (y1 * y1)) <= (circle[2] * circle[2])

    ans = 0
    diff = circle1[2]
    for i in range(circle1[0]-diff, circle1[0]+diff+1):
        for j in range(circle1[1]-diff, circle1[1]+diff+1):
            ans += (checkIn(i, j, circle1) and checkIn(i, j, circle2))
    return ans


print(countPoints([4, 5, 3], [6, 7, 2]))
# print(countPoints([3, 3, 2], [5, 3, 2]))
print(countPoints([12, 10, 6], [6, 9, 4]))
