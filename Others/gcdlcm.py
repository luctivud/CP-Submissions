li = [1591, 2021]
import math
def getgcd(li) :
	gcd = li[0]
	for i in li[1:]:
		gcd = math.gcd(gcd, i)
	return gcd
	
def getlcm(li):
	lcm = li[0]
	for i in li[1:]:
		lcm = (lcm * i) // math.gcd(lcm, i) 
	return lcm
	
print("lcm", getlcm(li))
print("hcf", getgcd(li))

lo = 1500
hi = 2500

for i in range(lo, hi):
	for j in range(i+1, hi):
		if getlcm([i, j]) == 74777:
			print(i, j)

# print(514%24, 514%18, 514%24)

# for i in range(200, 301):
# 	print()