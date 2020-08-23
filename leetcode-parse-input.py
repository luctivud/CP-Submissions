import sys

fileInput = open('input.txt', 'r')

lines = fileInput.readlines()
for line in lines:
	line = line.strip('[]')
	if ',' in line:
		print(" ".join(map(lambda x: x.strip(' \' ') ,line.split(','))))
	else:
		print(line.strip(' \' '))