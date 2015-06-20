with open('b1.in', 'r') as f:
	d = []
	for i in range(0, 3):
		n = int(f.readline().strip())
		dd = {}
		for j in range(0, n):
			s = f.readline().strip().split(' ')
			dd[s[0]] = int(s[1])
		d.append(dd)

	ss = {}
	for k1, v1 in d[0].iteritems():
		for k2, v2, in d[1].iteritems():
			for k3, v3, in d[2].iteritems():
				v = v1 + v2 + v3 
				p = [k1, k2, k3]
				if(v in ss):
					ss[v].append(p[:])
				else:
					ss[v] = [p[:]]

	n = int(f.readline().strip())
	for i in range(0, n):
		s = f.readline().strip().split(' ')
		v = 0
		for j in range(0, 3):
			v = v + d[j][s[j]]
		v = v + 1
		k = ss[v].pop()
		print "%s %s %s" % (k[0], k[1], k[2])
