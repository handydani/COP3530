while True:
	inp = raw_input()
	if inp == "0":
		break
	if len(inp) == 1:
		print 1
		continue
	numPoss = []
	numPoss.append(1)
	if  (inp[0] == "1" and inp[1] != "0") or (inp[0] == "2" and inp[1] in "123456"):
		numPoss.append(2)
	else:
		numPoss.append(1)
	for i in range(2, len(inp)):
		if inp[i] == "0":
			numPoss.append(numPoss[-2])
		elif inp[i-1] == "0":
			numPoss.append(numPoss[-1])
		elif (inp[i-1] == "1" and inp[i] != "0") or (inp[i-1] == "2" and inp[i] in "123456"):
			numPoss.append(numPoss[-2] +  numPoss[-1])
		else:
			numPoss.append(numPoss[-1])
	print numPoss[-1]


