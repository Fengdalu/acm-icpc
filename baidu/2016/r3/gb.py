import random
def gen(n):
    m = random.randint(1, n * n)
    k = random.randint(1, n)
    print n, m, k
    while(m != 0):
        x = random.randint(1, n)
        y = random.randint(1, n)
        print x, y
        m = m - 1

if(__name__ == "__main__"):
    __ = 1000
    print __
    for i in range(0, __):
        gen(14)
