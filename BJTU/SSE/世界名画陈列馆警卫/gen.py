PROC = 16

s = []
for i in range(0, PROC):
    s.append('')

cnt = 0
for n in range(1, 21):
    for m in range(n, 21):
        cur = "%d %d\n" % (n, m)
        s[cnt % PROC] = s[cnt % PROC] + cur
        cnt = cnt + 1

for i in range(0, PROC):
    with open('%d.dat' % i, 'w') as f:
        f.write(s[i])
        f.close()

sh = open("r.sh", 'w')
sh.write('g++ D.cpp -o D -O2\n')
for i in range(0, PROC):
    sh.write('./D %d.dat r.txt &\n' % i)
sh.close()
