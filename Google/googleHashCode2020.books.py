import math
import numpy as np
numberOfBooks, numberOfLibrary, numberOfDays = map(int, input().split())
scoreOfBooks = list(map(int, input().split()))
booksInLibrary = [];signupTime = []; shippingSpeed =[]; idOfBooksInLibrary = [];
toleranceFactor = [];gainFactor=[];bookScanFactor=[]
for i in range(numberOfLibrary):
    a,b,c =  map(int, input().split())
    booksInLibrary.append(a)
    signupTime.append(b)
    shippingSpeed.append(c)
    tempArr = set(map(int, input().split()))
    idOfBooksInLibrary.append(tempArr)
    toleranceFactor.append(numberOfDays-(math.ceil(a/c)+b))
    bookScanFactor.append(max(a,(numberOfDays-b)*c))
    ar = np.array(list(tempArr.copy()))
    np.sort(ar)
    su=0
    for i in range(max(0,len(ar)-(numberOfDays-b)*c),len(ar)):
        su+=scoreOfBooks[ar[i]]
    gainFactor.append(su)
    # speedFactor.append([toleranceFactor,gainFactor])
# print(booksInLibrary , signupTime , shippingSpeed , idOfBooksInLibrary)
# print(toleranceFactor,gainFactor,bookScanFactor)
    
gainFactorCopy = gainFactor.copy()
gainFactorCopy.sort()
libraryUsed=[];
for i in range(len(gainFactorCopy)-1,-1,-1):
    ind = gainFactor.index(gainFactorCopy[i])
    numberOfDays -= signupTime[ind]
    if numberOfDays<0:
        break
    libraryUsed.append(ind)
        
print(len(libraryUsed))
for i in libraryUsed:
    print(i)
        
        