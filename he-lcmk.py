#                           जय श्री राम

import sys; import math; from collections import *
from functools import reduce
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().split())
def get_list(): return list(get_ints())
def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e6) + 3

#sys.stdin  = open("input.txt","r"); sys.stdout = open("output.txt","w")

Prime = [0] * MAXN
Prime[0] = Prime[1] = 1
for i in range(4, MAXN, 2):
    Prime[i] = 2
i = 3
while i*i <= MAXN:
    if not Prime[i]:
        for j in range(2*i, MAXN, i):
            if not Prime[j]:
                Prime[j] = i
    i += 2
# print(Prime)

def power(x, y, p): 
    res = 1;
    x = x % p;  
    while (y > 0):
        if (y & 1): 
            res = (res * x) % p; 
        y = y >> 1; # y = y/2 
        x = (x * x) % p; 
    return res; 

def getfacto(n):
    while n > 1:
        if Prime[n] == 0:
            facto[n] += 1
            lcm[n] = max(lcm[n], facto[n])
            n = 1
        else:
            dumb = Prime[n]
            while n % dumb == 0:
                facto[dumb] += 1
                n //= dumb
            lcm[dumb] = max(lcm[dumb], facto[dumb])
    return



for _testcases_ in range(int(input())):
    n, m, fuck = get_ints()
    li = get_list()

    lcm = defaultdict(int)

    for i in li:
        facto = defaultdict(int)
        getfacto(i)
    ans = 1
    for k, v in lcm.items():
        if v > 0:
            ans *= (power(k, (fuck*v), m)) % m
            ans %= m
    print(ans % m)



    # li = list(map(lambda x: power(x, k, m), li))
    # lcm = reduce(lambda x, y: ((x*y)//math.gcd(x, y))%m, li)
    # print(lcm % m)
    
    # for i in range(2, MAXN):
    #     if lcm[i]:
    #         # print(i, lcm[i])
    #         ans *= power(i, lcm[i]*k, m)
    # ans = power(lcm, k, m)
    # lcm = [0] * MAXN
    # for i in range(2, MAXN):
    #     if Prime[i]:
    #         totalFac = 0


            





'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''