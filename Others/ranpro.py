#***************************************************************************#
#                 L U C T I V U D   - x -   L  I  G  H  T                   #
#                               00.20020702                                 #
#***************************************************************************#
import math
n= int(input())
li = list(map(int, input().split()))
ar = [1]
for i in range(len(li)):
  ar.append(li[i]*ar[i])
q = int(input())
# print(ar)
mux = [1]*(n+1)
for _ in range(q):
  k,a,b = map(int,input().split())
  if k==1:
    mxf = 1
    for i in range(a,b+1):
      mxf*=mux[i]
    try:
      sr = math.sqrt((mxf*ar[b])/ar[a-1])
      if (sr - math.floor(sr)) == 0:
        print("YES")
      else:
        print("NO")
    except:
      print("NO")
  else:
    mux[a]*=b
  
