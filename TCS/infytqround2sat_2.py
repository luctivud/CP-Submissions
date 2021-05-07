string = input().strip()
value = [0]
for i in range(9):
	num = int(input())
	value.append(num)
swap = 0
for i in range(len(s)):
	num = int(s[i])
	if swap == 1:
		if num <= value[num]:
			string[i] = str(value[num])
		else:
			break
	else:
		if num < value[num]:
			s[i] = str(value[num])
			swap = 1
		else:
			continue
for i in range(len(num)-1, -1, -1):
	