with open('b1.in', 'r') as f:
	d = []
	for i in range(0, 2):
		n = int(f.readline().strip())
		dd = {}
		for j in range(0, n):
			s = f.readline().strip().split(' ')
			dd[s[0]] = int(s[1])
		d.append(dd)

	n = int(f.readline().strip())
	ss1 = {}
	for j in range(0, n):
		s = f.readline().strip().split(' ')
		ss1[s[0]] = int(s[1])

	ss = {}

	for k1, v1 in d[0].iteritems():
		for k2, v2, in d[1].iteritems():
			v = v1 + v2
			p = [k1, k2]
			if(v in ss):
				ss[v].append(p[:])
			else:
				ss[v] = [p[:]]


	vis = set()
	n = int(f.readline().strip())
	for i in range(0, n):
		s = f.readline().strip().split(' ')
		t = d[0][s[0]] + d[1][s[1]] + ss1[s[2]] + 1
		flag = False

		for k, v in ss1.iteritems():
			if((t - v) in ss):
				for s1 in ss[t - v]:
					if(not (("".join(s1) + k) in vis)):
						flag = True
						vis.add("".join(s1) + k)
						print(s1[0] + " " + s1[1] + " " + k)
					if(flag == True):
						break
			if(flag == True):
				break
