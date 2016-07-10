T = input()

r1 = {}
r2 = {}
for ii in range(1, T + 1):
    n = input()
    a = set()
    b = set()
    c = set()
    ans = 0
    for i in range(0, n):
        w = raw_input().split(" ")
        if(not w[0] in r1):
            r1[w[0]] = set()
        if(not w[1] in r2):
            r2[w[1]] = set()
        r1[w[0]].add(w[1])
        r2[w[1]].add(w[0])
        a.add(w[0])
        b.add(w[1])
    s = set()
    tot = 0
    for w in a:
        flag = False
        for p in r1[w]:
            if(not (p in s)):
                s.add(p)
                flag = True
                break
        tot = tot + 1
    tot = tot + len(b) - len(s)
    ans =  tot
    print tot
    s = set()
    tot = 0
    for w in b:
        print w
        for p in r2[w]:
            if(not (p in s)):
                print p
                s.add(p)
                break
        tot = tot + 1
    print len(s)
    tot = tot + len(a) - len(s)
    print tot
    ans = min(ans, tot)
    print "Case #" + str(ii) + ": " + str(n - ans)
    break
