
import random
def gen(n, q):
    print n, q
    p = range(1, n + 1)
    random.shuffle(p)
    s = ""
    for i in p:
        s = s + str(i) + " "
    print s
    for i in range(0, q):
        op = random.randint(1, 4)
        l = random.randint(1, n)
        r = random.randint(l, n)
        c = random.randint(-2000, 2000)
        if(op != 4):
            print op, l, r, c
        else:
            print op, l, r

print 1
gen(10, 3)

