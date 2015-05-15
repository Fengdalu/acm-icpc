n = int(raw_input())
f = []

for i in range(0, n):
    f.append(list(raw_input()))

m = [[0, 0], [1, 0], [2, 0], [1, 1], [1, -1]]
for i in range(0, n):
    for j in range(0, n):
        if(f[i][j] == '#'):
            flag = True
            for k in range(0, 5):
                if i + m[k][0] < 0 or i + m[k][0] >= n or j + m[k][1] < 0 or j + m[k][1] >= n:
                    flag = False
                elif f[i + m[k][0]][j + m[k][1]] != '#':
                     flag = False
            if(flag):
                for k in range(0, 5):
                    f[i + m[k][0]][j + m[k][1]] = '.';

flag = True;

for i in range(0, n):
    for j in range(0, n):
        if(f[i][j] == '#'):
            flag = False;

if(flag):
    print 'YES'
else:
    print 'NO'
                      

