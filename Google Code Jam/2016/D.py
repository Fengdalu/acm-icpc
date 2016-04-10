T = input()
for ii in range(1, T + 1):
	line = raw_input().split(" ")
	k = int(line[0])
	c = int(line[1])
	s = int(line[2])
	ans = "Case #%d:" % ii
	for i in range(1, s + 1):
		ans += " " + str(i)
	print ans
