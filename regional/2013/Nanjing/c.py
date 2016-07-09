import random


def get():
    n = 50000
    target = random.randint(1, 1000000)

    l = range(1, n + 1)
    random.shuffle(l)

    print n, target
    for i in range(0, n):
        print i

    for i in range(0, n - 1):
        print l[i], l[i + 1]

for i in range(0, 10):
    get()

