def binarySearch (arr, l, r, x, se, prev): 
  
    # Check base case 
    if r >= l: 
  
        mid = l + (r - l) // 2
  
        # If element is present at the middle itself 
        if arr[mid] not in se: 
            prev = arr[mid]
            t1 = binarySearch(arr, l, mid-1, x, se, prev)
            if t1!=-1:
                return t1
            t2 = binarySearch(arr, mid + 1, r, x, se, prev)
            if t2!=-1:
                return t2
            return prev
        #     return mid 
          
        # # If element is smaller than mid, then it  
        # # can only be present in left subarray 
        # elif arr[mid] > x: 
  
        # Else the element can only be present  
        # in right subarray 
        else: 
            t1 = binarySearch(arr, l, mid-1, x, se, prev)
            if t1!=-1:
                return t1
            t2 = binarySearch(arr, mid + 1, r, x, se, prev)
            if t2!=-1:
                return t2
            return -1
  
    else: 
        # Element is not present in the array 
        return prev


for _ in range(int(input())):
    graph = []
    n = int(input())
    for i in range(n):
        li = list(map(int, input().split()))
        # li.pop(0)
        graph.append(li)
    se = set(); a1=-1; a2=-1; ansli = [-1]*n
    for i in range(n):
        f = binarySearch(graph[i],1, graph[i][0], -1, se, -1)
        ansli[i] = f
        se.add(f)
        # for j in range(1, graph[i][0]+1):
        #     if graph[i][j] not in se:
        #         se.add(graph[i][j])
        #         ansli[i] = j
        #         break
    for i in range(1, n+1):
        if i not in se:
            a2 = i
            break
    for i in range(n):
        if ansli[i] == -1:
            a1=i+1
            break
    if a1!=-1 and a2!=-1:
        print("IMPROVE")
        print(a1,a2)
    else:
        print("OPTIMAL")
