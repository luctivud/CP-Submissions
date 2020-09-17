#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#   '          .       ,     神 | 光      .     '        .      , #
#     .      '        Udit Gupta @luctivud         ,              #
#  ,    '   ELDIOS | LIGHT | GREED | CIPHER | XAYN | KIRA '    .  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
                ##     ##   ######   # #  ######
                ##     ##   ##  ##   ###    ##
                ##     ##   ##   #   # #    ##
                ###### ##   ######   # #    ##
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~| WORSHIPPER OF GREED |~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
import sys
import math as mt
# sys.setrecursionlimit(10**6)
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()
#########################################################################
def check(n, k): 
    a = list() 
    while n % 2 == 0: 
        a.append(2) 
        n = n // 2
    for i in range(3, mt.ceil(mt.sqrt(n)), 2): 
        while n % i == 0: 
            n = n / i; 
            a.append(i) 
    if n > 2: 
        a.append(n) 
    if len(a) < k:
        return False
    else:
        return True
for _testcases_ in range(int(input())):
    x, k = get_ints()
    if check(x, k):
        print(1)
    else:
        print(0)
# GENERATOR PROGRAM TO DERIVE THE RELATION
# def isPrime(n):
# 	count=0
# 	if n==1:
# 		return False
# 	for i in range(2, int(n**0.5)+1):
# 		if n%i==0:
# 			count+=1
# 	if count:
# 		return False
# 	return True
# d={}
# # lissy=[210*11, 210*11*2]
# lissy=[(2*3*5)**2]
# for i in lissy:
# 	a= i; x=0; k=0;
# 	for j in range(1, a+1):
# 		if a%j==0:
# 			x+=1
# 			if isPrime(j):
# 				k+=1
# 	try:
# 		d[k].add(x)
# 	except:
# 		d[k]=set({x})
# 	if k==2 and x==9:
# 		print(i, end=", ")
# for k , v in d.items():
# 	print(k, sorted(list(v)))
# # print(d)
# 	# print(k, x, i, end=" , ")
'''
1 [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]
2 [4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 27, 28, 30, 32, 33, 35, 36, 40]
3 [8, 12, 16, 18, 20, 24, 27, 28, 30, 32, 36, 40, 42, 45, 48, 50, 54, 56]
4 [16, 24, 32, 36, 40, 48, 54, 56, 60, 64, 72]
5 [32, 48, 64]
'''