#***************************************************************************#
#                 L U C T I V U D   - x -   L  I  G  H  T                   #
#                               00.20020702                                 #
#***************************************************************************#
import math
# GET DIVISORS HERE
# def getDivisors(n) : 
  

# MAIN HERE
for _ in range(int(input())):
  nx, ny = map(int, input().split())
  lx = list(map(int, input().split()))
  ly = list(map(int, input().split()))
  nposx=0
  nnegx=0
  nposy=0
  nnegy=0
  posx = {}
  negx = {}
  posy = {}
  negy = {}
  zero = False
  count = 0

  # CREATE DICT HERE
  for ele in lx:
    if ele>0:
      posx[ele]=1
      nposx+=1
    elif ele<0:
      negx[ele]=1
      nnegx+=1
    else:
      zero = True
  for ele in ly:
    if ele>0:
      posy[(ele)]=1
      nposy+=1
    elif ele<0:
      negy[(ele)]=1
      nnegy+=1
    else:
      zero = True
  # CHECK FOR ELEMENT'S FACTOR HERE
  for ele in ly:
    if ele!=0:
      n=ele**2
      i = 1
      while i <= math.sqrt(n): 
        if (n % i == 0) : 
          if (n / i == i) : 
            # print (i,i, end=" ")
            try:
              if posx[i]==1 and negx[i]==1:
                count+=1
            except:
              pass
          else : 
            # print (i, int(n/i), end=" ") 
            try:
              if posx[i]==1 and negx[int(n/i)]==1:
                count+=1
            except:
              pass
            try:
              if negx[i]==1 and posx[int(n/i)]==1:
                count+=1
            except:
              pass
        i = i + 1
  
  for ele in lx:
    if ele!=0:
      n=ele**2
      i = 1
      while i <= math.sqrt(n): 
        if (n % i == 0) : 
          if (n / i == i) : 
            # print (i,i, end=" ")
            try:
              if posy[i]==1 and negy[i]==1:
                count+=1
                print("try",end=" ")
            except:
              pass
          else : 
            print (i, int(n/i), end=" ") 
            try:
              if posy[i]==1 and negy[int(n/i)]==1:
                count+=1
                print("try",end=" ")
            except:
              pass
            try:
              if negy[i]==1 and posy[int(n/i)]==1:
                count+=1
                print("try",end=" ")
            except:
              pass
        i = i + 1

  if zero:
    count += (nposx+nnegx) * (nposy+nnegy)
  print(count)
  # print()
  
  
  
#END END END END END EDN------------------------------------------- 
  # print(lx, ly)
  # print(posx,negx)
  # print(posy,negy)
  
#   for px in posx:
#     for nx in negx:
#       searchEl = (px*nx)**0.5
#       # print(searchEl)
#       if math.floor(searchEl) == searchEl:
#         if searchEl in posy:
#           count+=1
#         if searchEl in negy:
#           count+=1
#   for py in posy:
#     for ny in negy:
#       searchEl = (py*ny)**0.5
#       if math.floor(searchEl) == searchEl:
#         if searchEl in posx:
#           count+=1
#         if searchEl in negx:
#           count+=1
  