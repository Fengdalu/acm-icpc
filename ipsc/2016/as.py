n = input()
while(n != 0):
    n = n - 1
    l = raw_input()
    l = raw_input().split(" ")
    s = ""
    for w in l:
        s = s + w
    s = s + "AA"
    print s

