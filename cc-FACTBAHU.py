#                          JAI SHREE RAM

import math; from collections import *
import sys; from functools import reduce

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def getlistofstring(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e5)

# sys.setrecursionlimit(10**6)
# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")
d = {1: 1, 2: 2, 3: 4, 4: 6, 6: 12, 5: 16, 8: 24, 9: 36, 10: 48, 12: 60, 7: 64, 16: 120, 15: 144, 18: 180, 14: 192, 20: 240, 24: 360, 21: 576, 30: 720, 32: 840, 27: 900, 28: 960, 11: 1024, 36: 1260, 25: 1296, 40: 1680, 48: 2520, 42: 2880, 22: 3072, 45: 3600, 13: 4096, 60: 5040, 35: 5184, 54: 6300, 50: 6480, 56: 6720, 64: 7560, 33: 9216, 72: 10080, 26: 12288, 63: 14400, 80: 15120, 44: 15360, 84: 20160, 90: 25200, 70: 25920, 96: 27720, 75: 32400, 39: 36864, 81: 44100, 100: 45360, 66: 46080, 49: 46656, 108: 50400, 120: 55440, 112: 60480, 52: 61440, 17: 65536, 55: 82944, 128: 83160, 126: 100800, 88: 107520, 144: 110880, 105: 129600, 160: 166320, 135: 176400, 140: 181440, 78: 184320, 34: 196608, 168: 221760, 150: 226800, 99: 230400, 98: 233280, 19: 262144, 180: 277200, 132: 322560, 65: 331776, 192: 332640, 162: 352800, 110: 414720, 104: 430080, 200: 498960, 216: 554400, 51: 589824, 224: 665280, 189: 705600, 240: 720720, 77: 746496, 38: 786432, 125: 810000, 210: 907200, 117: 921600, 176: 967680, 68: 983040}
ans = {}
for i in range(200, 0, -1):
    ans[i] = min(d.get(i, float('inf')), ans.get(i+1, float('inf')))
# print(ans)

for _testcases_ in range(int(input())):
    print(ans[int(input())])

'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
CODE FOR GENERATING d in line 16:
prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]
def solve(n):
	ans = 1
	for i in prime:
		if n % i == 0:
			temp = 0
			while n%i==0:
				temp += 1
				n //= i
			ans *= (temp+1)
		if i > n:
			break
	return ans
d = {}
for i in range(1, int(1e6)):
	t = solve(i)
	if t not in d:
		d[t] = i
	else:
		d[t] = min(d[t], i)
print(d)
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''