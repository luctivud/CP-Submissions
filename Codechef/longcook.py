#***************************************************************************#
#                 L U C T I V U D   - x -   L  I  G  H  T                   #
#                               00.20020702                                 #
#***************************************************************************#
import math
li = [3, 9, 14, 15, 20, 25, 26, 31, 37, 42, 43, 48, 53, 54, 59, 65, 70, 71, 76, 81, 82, 87, 93, 98, 99, 105, 110, 111, 116, 121, 122, 127, 133, 138, 139, 144, 149, 150, 155, 161, 166, 167, 172, 177, 178, 183, 189, 194, 195, 200, 201, 206, 207, 212, 217, 218, 223, 229, 234, 235, 240, 245, 246, 251, 257, 262, 263, 268, 273, 274, 279, 285, 290, 291, 296, 302, 303, 308, 313, 314, 319, 325, 330, 331, 336, 341, 342, 347, 353, 358, 359, 364, 369, 370, 375, 381, 386, 387, 392, 397, 398]
for _ in range(int(input())):
  # li = [4,9,10,15,21,26,27]
  m1, y1 = map(int, input().split())
  m2, y2 = map(int, input().split())
  if m1 > 2:
    y1 += 1
  if m2 < 2:
    y2 -= 1
  count = 0
  y1m = y1%400
  y2m = y2%400
  st = 1
  en = 101
  nxty1 = ((y1//400)+1)*400
  prvy2 = (y2//400)*400
  if y2-y1 <=400:
    for i in range(y1,y2+1):
      if i%400 in li:
        count+=1 
  else:
    for i in range(y1,nxty1):
      if i%400 in li:
        count += 101 - li.index(i%400)
        break
        # count+=1
    # for i in range(nxty1,prvy2):
    #   if i%400 in li:
    #     count+=1
    count+= ((prvy2-nxty1)//400)*101
    for i in range(y2,prvy2-1,-1):
      if i%400 in li:
        count+= li.index(i%400)+1
        break
  print(count)
    # for i in range(101):
    #   if li[i]>=y1m:
    #     st = i
    #     break
    # for i in range(101):
    #   if li[i]>=y2m:
    #     en = 101-i
    # count = en + st
    # if en<st:
    #   count = st - en + 1
  # while y1%400<398 or y1==y2:
  #   count+=1
  #   y1+=1
  # while y2%400>0 or y1==y2:
  #   count+=1
  #   y2-=1
  # if y1==y2:
  #   if y1%400 in li:
  #     count+=1
  # else:
  #   y1+=1
  # y1y = y1//400
  # y2y = y2//400
  # count+= ((y2y-y1y-1)*101)
  # for i in range(y1,y2+1):
  #   if i%400 in li:
  #     start = li.index(i%400)
  #     break
  # for i in range(y2,y1-1,-1):
  #   if i%400 in li:
  #     end = li.index(i%400)
  #     break
  # count = end - start + ((y2y - y1y)*101) + 1
  # if start == end == -1:
  #   count = 0
  # print(count)
  # ml = y1%400
  # mu = y2%400
  # y1 = y1+400-ml
  # y2 = y2+0-mu
  # for i in range(len(li)):
  #   if li[i] >= ml:
  #     count += 101-i
  #     # print(count)
  #     break
  # for i in range(len(li)):
  #   if li[i] > mu:
  #     count += (i)
  #     # print(count)
  #     break
  # # print(y1,y2,count,ml,mu)
  # print(count+(math.floor((y2-y1)/400))*101)