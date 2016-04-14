
for i in range(0, 10 ** 6):
	s = set()	
	step = 0
	for j in range(1, 10 ** 6):
		pre = len(s)	
		for ch in list(str(i * j)):
			s.add(ch)
		if(len(s) == 10):
			print i, j * i
			break
		if(pre == len(s)):
			step = step + 1
		else:
			step = 0
		if(step == 1000):
			break;
	if(len(s) != 10):
		print i, -1
