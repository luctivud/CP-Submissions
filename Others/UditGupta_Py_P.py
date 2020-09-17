'''
PROGRAM FOR BINARY SEARCH
NAME : UDIT GUPTA
R.NO : 1803210166
SEC : CSE_A
'''

def binarysearch(arr, val: int, r: int, l: int = 0) -> int:
    while l <= r: 
        mid = l + (r - l) // 2; 
        if arr[mid] == val: 
            return mid 
        elif arr[mid] < val: 
            l = mid + 1
        else: 
            r = mid - 1
    return -1

# MAIN
li = list(map(int, input("Enter space seperated sorted list ").split()))
val = int(input("Enter the number to be searched "))

ind = binarysearch(li, val, len(li)-1) + 1

if ind:
    print("Element({}) found at {} index. (1-based indexing)".format(val, ind))
else:
    print("Element({}) not found.".format(val))
    
# END