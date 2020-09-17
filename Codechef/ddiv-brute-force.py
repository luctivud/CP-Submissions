dp=[[0, i] for i in range(1000)]
# print(dp)
for i in range(1, 1000):
	ans = 0
	for j in range(2,i+1):
		if i%j==0:
			boo=False
			for k in range(2, j+1):
				# print("jg")
				temp = k
				count=0
				while(temp<j):
					temp*=k
					count+=1
				# if i==4:
					# print(temp,j, "/", end=" ")
				if temp==j and count>0:
					boo=True
			if boo:
				ans+=j
				# if i==16:
				# 	print(ans,i,j,k)
					# print("ch",ans, end="/")
	# if i==16:
	# 	print(ans)
	dp[i][0]=dp[i-1][0]+ans+1
last = 0; mx=0
for i in dp:
	# print(i,i[0]-i[1]-last, end=" / ")
	# print(i[0]-i[1]-last, end=" / ")
	mx = max(mx, i[0]-i[1]-last)
	last = i[0]-i[1]
	print(i[1],"-", i[0], end=", ")
# print()
# print(mx)