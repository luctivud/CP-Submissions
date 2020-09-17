from collections import Counter 
from math import factorial
def rncf(n, r): 
    return ((factorial(n) // (factorial(r)  
                * factorial(n - r)))) 
T=int(input())
for Heyy in range(T):
    n=int(input())
    a=[int(i) for i in input().split(" ")]
    q=int(input())
    for each in range(q):
        L,R=[int(i) for i in input().split(" ")]
        l=a[L-1:R]
        answer=dict(Counter(l))
        fre=list(answer.values())
        xor=0
        print(fre)
        for i in fre:
            xor=xor^i
        if xor == 0:
            print("0")
        else:
            answerrr=0
            for each in fre:
                print(each,xor^each,xor)
                n=each
                r=xor^each
                if n > r:
                    answerrr+=rncf(n,r)
            print(answerrr%998244353)