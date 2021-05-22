#   J A I  S H R E E  R A M   #


import math, sys, collections, functools, time, itertools;

# sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


N = 200001
 
# array to store inverse of 1 to N
factorialNumInverse = [None] * (N + 1)
 
# array to precompute inverse of 1! to N!
naturalNumInverse = [None] * (N + 1)
 
# array to store factorial of
# first N numbers
fact = [None] * (N + 1)
 
# Function to precompute inverse of numbers
def InverseofNumber(p):
    naturalNumInverse[0] = naturalNumInverse[1] = 1
    for i in range(2, N + 1, 1):
        naturalNumInverse[i] = (naturalNumInverse[p % i] *
                                   (p - int(p / i)) % p)
 
# Function to precompute inverse
# of factorials
def InverseofFactorial(p):
    factorialNumInverse[0] = factorialNumInverse[1] = 1
 
    # precompute inverse of natural numbers
    for i in range(2, N + 1, 1):
        factorialNumInverse[i] = (naturalNumInverse[i] *
                                  factorialNumInverse[i - 1]) % p
 
# Function to calculate factorial of 1 to N
def factorial(p):
    fact[0] = 1
 
    # precompute factorials
    for i in range(1, N + 1):
        fact[i] = (fact[i - 1] * i) % p
 
# Function to return nCr % p in O(1) time
def Binomial(N, R, p):
     
    # n C r = n!*inverse(r!)*inverse((n-r)!)
    # print(N, R, p)
    ans = ((fact[N] * factorialNumInverse[R])% p *
                      factorialNumInverse[N - R])% p
    return ans




mod = int(1e9) + 7;

def solveEachTest(_TestCase):
	# printsp("Case #{}: ".format(_TestCase)) 
	n, m = Read_Ints()

	zeta = 0
	for (i, j) in [(1, 2), (2, 1)]:
		# print(i, j)
		w1 = Binomial(i+j-2, i-1, mod)
		w2 = Binomial(n+m-i-j, n-i, mod)
		zeta += w1 * w2
	zeta *= 2
	# print(zeta)
	q = n*m-2
	cnt = (n+m-2) // 2
	p = zeta * cnt
	if not ((n & 1) ^ (m & 1)):
		p -= zeta // 2
	# print(p, q, cnt)
	p = (Binomial(n+m-2, n-1, mod) * q) - p
	# print(p, q)
	print(((p) * pow(q, mod-2, mod)) % mod)
	






_T0T4 = 1;
_T0T4 = int(input()) 
InverseofNumber(mod)
InverseofFactorial(mod)
factorial(mod)	
for _TestCase in range(1, _T0T4 + 1): 
	solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

