#***************************************************************************#
#                 L U C T I V U D   - x -   L  I  G  H  T                   #
#                               00.20020702                                 #
#***************************************************************************#
totalProfit= 0
prices = [100, 75, 50, 25]
for _ in range(int(input())):
    li = [[0 for x in range(4)] for y in range(4)]
    for __ in range(int(input())):
        c, show = input().strip().split()
        li[ord(c)-ord("A")][int(show)//3 - 1] += 1
        
    cases = [[0 for x in range(4)] for y in range(24)]        
    
    cases[0] = [li[0][0], li[1][1], li[2][2], li[3][3]]
    cases[1] = [li[0][0], li[1][1], li[3][2], li[2][3]]
    cases[2] = [li[0][0], li[2][1], li[1][2], li[3][3]]
    cases[3] = [li[0][0], li[2][1], li[3][2], li[1][3]]
    cases[4] = [li[0][0], li[3][1], li[2][2], li[1][3]]
    cases[5] = [li[0][0], li[3][1], li[1][2], li[2][3]]

    cases[6] = [li[1][0], li[0][1], li[2][2], li[3][3]]
    cases[7] = [li[1][0], li[0][1], li[3][2], li[2][3]]
    cases[12] = [li[1][0], li[2][1], li[0][2], li[3][3]]
    cases[13] = [li[1][0], li[3][1], li[0][2], li[2][3]]
    cases[18] = [li[1][0], li[2][1], li[3][2], li[0][3]]
    cases[19] = [li[1][0], li[3][1], li[2][2], li[0][3]]

    cases[8] = [li[2][0], li[0][1], li[3][2], li[1][3]]
    cases[9] = [li[2][0], li[0][1], li[1][2], li[3][3]]
    cases[14] = [li[2][0], li[1][1], li[0][2], li[3][3]]
    cases[16] = [li[2][0], li[3][1], li[0][2], li[1][3]]
    cases[20] = [li[2][0], li[1][1], li[3][2], li[0][3]]
    cases[22] = [li[2][0], li[3][1], li[1][2], li[0][3]]

    cases[10] = [li[3][0], li[0][1], li[2][2], li[1][3]]
    cases[11] = [li[3][0], li[0][1], li[1][2], li[2][3]]
    cases[15] = [li[3][0], li[1][1], li[0][2], li[2][3]]
    cases[17] = [li[3][0], li[2][1], li[0][2], li[1][3]]
    cases[21] = [li[3][0], li[1][1], li[2][2], li[0][3]]
    cases[23] = [li[3][0], li[2][1], li[1][2], li[0][3]]

    profit = -999999
    for row in cases:
        row.sort()
        s = row[0] * prices[3] + row[1] * prices[2] + row[2] * prices[1] + row[3] * prices[0] - row.count(0) * 100
        if s > profit:
            profit = s
    print(profit)
    totalProfit += profit
print(totalProfit)