T = input()

for ii in range(1, T + 1):
    n = input()
    a = {}
    b = {}
    ans = 0
    for i in range(0, n):
        w = raw_input().split(' ')
        a1 = w[0]
        a2 = w[1]
        if(not a1 in a):
            a[a1] = 0
        if(not a2 in b):
            b[a2] = 0
        a[a1] = a[a1] + 1
        b[a2] = b[a2] + 1
    tot = 0
    for k, v in a.items():
        tot = tot + v - 1
    ans = tot
    for k, v in b.items():
        tot =  tot + v - 1
    ans = min(ans, tot)
    print "Case #" + str(ii) + ": " + str(ans)
