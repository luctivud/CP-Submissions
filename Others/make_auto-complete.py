while True:
	try:
		line = input()
		line = line.strip(",")
		line += '<('
		idx = min(line.index("<"), line.index("("))
		trigger = line[:idx].strip("\"")
		print(trigger, line.strip("<(\""))
		print("{{\"trigger\": \"{}\", \"contents\": \"{}\"}}, ".format(trigger, line.strip("<(\"")))
	except:
		break