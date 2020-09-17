t = 100
for x in range(t):
	n = x+1
	diff = int(input())
	s = input()
	fS = 0;
	sS = 0;
	for i in range(n):
		if s[i] == '1':
			fS += (i+1) ** 3
		else:
			sS += (i+1) ** 3

	if abs(fS - sS) == diff:
		print(n, "OK", abs(fS - sS))
	else:
		print(n, "WRONG", abs(fS - sS))
