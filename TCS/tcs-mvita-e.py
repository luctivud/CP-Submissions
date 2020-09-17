import sys; import math; from collections import *
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9+7); SEXYMOD = 998244353; MAXN = int(1e5)

N = 1001
factorialNumInverse = [None] * (N + 1) 
naturalNumInverse = [None] * (N + 1) 
fact = [None] * (N + 1) 
def InverseofNumber(p): 
    naturalNumInverse[0] = naturalNumInverse[1] = 1
    for i in range(2, N + 1, 1): 
        naturalNumInverse[i] = (naturalNumInverse[p % i] * (p - int(p / i)) % p) 
  
def InverseofFactorial(p): 
    factorialNumInverse[0] = factorialNumInverse[1] = 1
    for i in range(2, N + 1, 1): 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p 
  
def factorial(p): 
    fact[0] = 1
    for i in range(1, N + 1): 
        fact[i] = (fact[i - 1] * i) % p 

def Binomial(N, R, p): 
    ans = ((fact[N] * factorialNumInverse[R])% p * factorialNumInverse[N - R])% p 
    return ans 
  
# sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

InverseofNumber(UGLYMOD) 
InverseofFactorial(UGLYMOD) 
factorial(UGLYMOD) 
for _testcases_ in range(int(input())):
    n, t, m = get_ints()
    q = Binomial(n, t, UGLYMOD)
    if n-m < t:
        ans = 1
    else:
        none = Binomial(n-m, t, UGLYMOD)
        p = q-none
        if p < 0:
            p += UGLYMOD
        ans = (p * pow(q, UGLYMOD-2, UGLYMOD)) % UGLYMOD
    print(ans)


'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
precomputing factorials : geeksforgeeks
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''