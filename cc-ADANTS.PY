#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# Udit Gupta @luctivud  神 | LIGHT | GREED | CIPHER | XAYN
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
                ##     ##   ######   # #  ######
                ##     ##   ##  ##   ###    ##
                ##     ##   ##   #   # #    ##
                ###### ##   ######   # #    ##
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#                   | WORSHIPPER OF GREED | 
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
import math
points = 0
oddOdd = []; evenOdd = []; oddEven = []; evenEven = [];
for _points_ in range(int(input())):
    li = list(map(int, input().split()))
    li.append(_points_+1)
    if li[0]%2 and li[1]%2:
        oddOdd.append(li)
    elif li[0]%2 == 0 and li[1]%2 == 1:
        evenOdd.append(li)
    elif li[0]%2 == 0 and li[1]%2 == 0:
        evenEven.append(li)
    else:
        oddEven.append(li)
    points += 1
ansInstructions = []
bool1 = True; bool2 = True
loopCount = 0
lastRem = []
while(bool1 or bool2):
    # print(1)
    allPointsType = [oddOdd, evenOdd, evenEven, oddEven]
    # print(allPointsType)
    lenArr = [len(oddOdd), len(evenOdd), len(evenEven), len(oddEven)]
    pointType = lenArr.copy()
    lenArr.sort()
    bool1 = False; bool2 = False
    # prev = lenArr[0]
    # first = pointType.index(lenArr[0])
    indArr = [0,0,0,0]
    for i in range(4):
        indArr[i] = pointType.index(lenArr[i])
        pointType[indArr[i]] = -1
    first = indArr[0]; second = indArr[1]
    third = indArr[2]; fourth = indArr[3]

    i = 0; j = 0;
    tempcount1 = 0; tempcount2 = 0
    arr1 = allPointsType[first]; arr2 = allPointsType[second]
    arr3 = allPointsType[third]; arr4 = allPointsType[fourth]
    forRemove1 = []; forRemove2 = [];
    while(i < len(allPointsType[first]) and j < len(allPointsType[second])):
        bool1 = True
        if tempcount1%2 == 0:
            ansInstructions.append([2, arr2[j][2], arr1[i][2]])
            forRemove2.append(arr2[j])
            j+=1
        else:
            ansInstructions.append([2, arr1[i][2], arr2[j][2]])
            forRemove1.append(arr1[i])
            i+=1
        tempcount1+=1
    for el in forRemove1:
        arr1.remove(el)
    for el in forRemove2:
        arr2.remove(el)
    i = 0; j = 0;
    forRemove1 = []; forRemove2 = [];
    while(i < len(allPointsType[third]) and j < len(allPointsType[fourth])):
        bool2 = True
        if tempcount2%2 == 0:
            # print(arr4[j], arr3[i])
            ansInstructions.append([2, arr4[j][2], arr3[i][2]])
            forRemove2.append(arr4[j])
            j+=1
        else:
            ansInstructions.append([2, arr3[i][2], arr4[j][2]])
            forRemove1.append(arr3[i])
            i+=1
        tempcount2+=1
    for el in forRemove1:
        arr3.remove(el)
    for el in forRemove2:
        arr4.remove(el)
    lastRem = allPointsType.copy()
# print(4/2 == 4//2)
for el in allPointsType:
    if len(el)>1:
        for i in range (len(el)-1):
            thisPoint = el[i]
            nxtPoint = el[i+1]
            try:
                slope = (thisPoint[1] - nxtPoint[1])/(thisPoint[0] - nxtPoint[0])
                for j in range(min(thisPoint[0], nxtPoint[0])+1, max(thisPoint[0], nxtPoint[0])):
                    if (slope * (j - thisPoint[0]))+thisPoint[1] == math.floor((slope * (j - thisPoint[0]))+thisPoint[1]):
                        ansInstructions.append([2, thisPoint[2], nxtPoint[2]])
                ansInstructions.append([2, thisPoint[2], nxtPoint[2]])
            except:
                if thisPoint[0] == nxtPoint[0]:
                    for j in range(min(thisPoint[1], nxtPoint[1])+1, max(thisPoint[1], nxtPoint[1])):
                        ansInstructions.append([2, thisPoint[2], nxtPoint[2]])
                    ansInstructions.append([2, thisPoint[2], nxtPoint[2]])

# print(ansInstructions)
print(len(ansInstructions))
for ele in ansInstructions:
    for i in ele:
        print(i, end = " ")
    print()