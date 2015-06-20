with open('a2.in', 'r') as f:
	t = int(f.readline())
	for ii in range(0, t):
		f.readline()
		l = list(f.readline().strip())
		s = 0
		for i in range(0, 2 ** len(l)):
			p = i
			x = []
			y = []
			for n in l:
				if(p % 2 == 0):
					x.append(n)
				else: 
					y.append(n)
				p = p / 2
			if(x == [] or y == []):
				continue
			x.sort()	
			y.sort()
			x.reverse()
			y.reverse()
			x = int(''.join(x))
			y = int(''.join(y))
			s = max(s,  x + y)
		print s
