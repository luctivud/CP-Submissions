for __ in range(int(input())):
	s = input()
	p = input()
	from collections import Counter
	c = Counter(s)
	for i in p:
		c[i] -= 1
	first_letter = p[0]
	for k, v in sorted(c.items()):
		if k <= first_letter:
			print(k * v, end="")
	print(p, end ="")
	for k, v in sorted(c.items()):
		if k > first_letter:
			print(k * v, end="")
	print()