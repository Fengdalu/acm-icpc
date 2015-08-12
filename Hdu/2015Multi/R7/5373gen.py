with open('input.txt', 'w') as f:
	import random as r
	for i in range(0, 1000):
		f.write("%d %d\n" % (r.randint(0, 10000), r.randint(0, 100000)))
	f.write("-1 -1\n")
	f.close()