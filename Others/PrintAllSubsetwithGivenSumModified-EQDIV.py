def printAllSubsetsRec(arr, n, v, sum) : 
    if (sum == 0) : 
        s = ""
        s2 = ""
        v = set(v)
        global N
        for j in range(N):
            if ((j+1)**k) in v:
                s += '1'
                s2 += '0'
            else:
                s2 += '1'
                s += '0'
        # print(s)
        D[s].add(k)
        D[s2].add(k)
        # for value in v : 
        #     print(value, end=" ") 
        # print() 
        return
    if (n == 0): 
        return
  
    printAllSubsetsRec(arr, n - 1, v, sum) 
    v1 = [] + v 
    v1.append(arr[n - 1]) 
    printAllSubsetsRec(arr, n - 1, v1, sum - arr[n - 1]) 
  
def printAllSubsets(arr, n, sum): 
  
    v = [] 
    printAllSubsetsRec(arr, n, v, sum) 
  

from collections import defaultdict

D = defaultdict(set)
k = int(input())
T = int(input())
for TT in range(T):

    N = int(input())

    arr = []
    for i in range(N):
        arr.append((i+1)**k)
    xx = sum(arr)
    print(xx)
    su = xx // 2
    # print(su)
    printAllSubsets(arr, N, su+1) 

    # k += 1
    # # k -= 2
    # arr = []
    # for i in range(N):
    #     arr.append((i+1)**(k))
    # su = sum(arr) // 2
    # printAllSubsets(arr, N, su) 

    # k += 1
    # arr = []
    # for i in range(N):
    #     arr.append((i+1)**(k))
    # su = sum(arr) // 2
    # printAllSubsets(arr, N, su) 

# print(*D.items(), sep="\n")
for ke, va in (D.items()):
    if len(va) > 0:
        print(ke, va)

  