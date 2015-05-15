n = int(raw_input())

a = []
b = []

for i in range(0, n + 1):
    a.append(0)
    b.append(0)

for i in range(1, n * (n - 1) / 2):
    r = raw_input().split(' ')
    x = int(r[0])
    y = int(r[1])
    a[x] = a[x] + 1
    b[y] = b[y] + 1

i = 1
p1 = -1
p2 = -1

    
while(True):
    if a[i] + b[i] + 1 != n:
        p1 = i
        break
    i = i + 1
    
i = i + 1
while(True):
    if a[i] + b[i] + 1 != n:
        p2 = i
        break
    i = i + 1

if a[p1] - b[p1] > a[p2] - b[p2]:
    print '%d %d' % (p1, p2)
else:
    print '%d %d' % (p2, p1)
