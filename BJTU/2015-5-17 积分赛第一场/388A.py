n = int(raw_input())
f = raw_input().split(' ')

for i in range(0, n):
    f[i] = int(f[i])
f.sort()
ans = 0;
while(len(f)):
    c = 0
    i = 0
    while(True):
        if i >= len(f):
            break;
        if f[i] >= c:
            f.pop(i)
            c = c + 1
        else:
            i = i + 1
    ans = ans + 1

print ans
