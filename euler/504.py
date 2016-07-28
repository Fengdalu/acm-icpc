from math import sqrt

m = 100
tot = 0
def cc(a, b, m):
    ans = 0
    for x in range(0, min(a, m)):
        t = 0
        if((a * b - b * x) % a == 0):
            t = (a * b - b * x) / a
        else:
            t = int((a * b - b * x) / a) + 1
        t = abs(t)
        if(x != m):
            ans = ans + max(1, t)
    return ans

def cal(a, b, c, d, m):
    cnt = 0
    cnt = cnt + cc(a, b, m)
    cnt = cnt + cc(c, b, m)
    cnt = cnt + cc(c, d, m)
    cnt = cnt + cc(a, d, m)
    cnt = cnt - a
    cnt = cnt - b
    cnt = cnt - c
    cnt = cnt - d
    return cnt + 1


for i in range(1, m + 1):
    for j in range(1, m + 1):
        for k in range(1, m + 1):
            for p in range(1, m + 1):
                q = cal(i, j, k, p, m)
                if(int(sqrt(q)) * int(sqrt(q)) == q):
                    tot = tot + 1

print tot
