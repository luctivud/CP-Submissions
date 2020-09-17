'''     J A I ~ S H R E E ~ R A M     '''

# Title: cc-MAGICMED.py
# created on: 18-07-2020 at 22:55:02
# Creator & Template : Udit Gupta "@luctivud"
# https://github.com/luctivud
# https://www.linkedin.com/in/udit-gupta-1b7863135/


import math; from collections import *
import sys; from functools import reduce
from itertools import groupby

# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def get_string(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")


DIRECTIONS = [[0, 1], [0, -1], [1, 0], [1, -1]] #up, down, right, left
NEIGHBOURS = [(i, j) for i in range(-1, 2) for j in range(-1, 2) if (i!=0 or j!=0)]


OrdUnicode_a = ord('a'); OrdUnicode_A = ord('A')
CAPS_ALPHABETS = {chr(i+OrdUnicode_A) : i for i in range(26)}
SMOL_ALPHABETS = {chr(i+OrdUnicode_a) : i for i in range(26)}


MOD_JOHAN = int(1e8)+7; MOD_LIGHT = 998244353; INFINITY = float('inf')
MAXN_EYEPATCH = int(1e5)+1; MAXN_FULLMETAL = 501

# Custom input output is now piped through terminal commands.

def power(x, y, p): 
    res = 1;
    x = x % p;  
    while (y > 0):
        if (y & 1): 
            res = (res * x) % p; 
        y = y >> 1; # y = y/2 
        x = (x * x) % p; 
    return res; 


def totient(n) :
    # print("yo")
    res = 1
    p = 2 
    while p**2 <= n :
        if(n%p == 0) : 
            res *= (p-1)
            n //= p
        while(n%p == 0) :
            res *=  p
            n //= p
        p += 1
    if n != 1 :
        res *= (n-1)
    return res
 

def modpow(p, z, b, c, m) : # (p^z)^(b^c) mod m
    if m == 2:
        return p % m
    cp = 0
    while m % p == 0 :
        cp += 1
        m //= p
    t = totient(m)
    exponent = ((power(b,c,t)*z)%t + t - (cp%t))%t
    return pow(p, cp)*power(p, exponent, m)
 

def solve(a,b,c,m) : #split
    result = 1
    p = 2
    while p**2 <= a :
        cp = 0
        while a%p == 0 :
            a //= p
            cp += 1
        if cp != 0 :
           temp =  modpow(p,cp,b,c,m)
           result *= temp
           result %= m
        p += 1
    if a != 1 :
        result *= modpow(a, 1, b, c, m)
    return result % m

for _testcases_ in range(int(input())): 
    a, b, c, m, p = get_ints()
    ans = solve(a, b, c, m)
    if ans == 0:
        print("NO 0")
    else:
        print("YES", ((ans % MOD_JOHAN) * (p % MOD_JOHAN)) % MOD_JOHAN)




'''
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here, otherwise.
'''
