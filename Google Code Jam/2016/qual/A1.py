
T = input()
for ii in range(1, T + 1):
	i = input()	
	s = set()	
	step = 0
	for j in range(1, 10 ** 6):
		pre = len(s)	
		for ch in list(str(i * j)):
			s.add(ch)
		if(len(s) == 10):
			print "Case #%d: %d" % (ii, i * j)
			break
		if(pre == len(s)):
			step = step + 1
		else:
			step = 0
		if(step == 1000):
			break;
	if(len(s) != 10):
		print "Case #%d: INSOMNIA" % ii
