def check(n, k):
    tot = 0
    for i in range(0, n + 1):
        s = str(i)
        flag = True
        for j in range(0, len(s)):
            for p in range(1, k):
                if(p + j >= len(s)):
                    break
                if(s[j] == s[p + j]):
                    flag = False

        if(flag == True):
            tot = tot + 1

    return tot


print check(1000, 5) - 1
