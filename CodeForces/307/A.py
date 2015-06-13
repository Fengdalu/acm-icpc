n = int(raw_input())
f = raw_input().split(' ')
d = {}
for i in range(0, len(f)):
        f[i] = int(f[i])
for x in f: 
	if(x in d):
		d[x] = d[x] + 1
	else:
		d[x] = 1

result = ""
for x in f:
	ans = 0
	for i in range(x + 1, 2001):
		if(i in d):
			ans = ans + d[i]
	result = result + str(ans + 1) + " "

print result
