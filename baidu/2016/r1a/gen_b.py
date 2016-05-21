import random

p = range(0, 16)
q = map(lambda x: x % 2, range(0, 16))
def gen():
    print 16
    random.shuffle(p)
    random.shuffle(q)
    for i in range(0, 16):
        if(q[i] == 0):
            print random.randint(-10000, 10001), " ", p[i]
        else:
            print random.randint(-10000, 10001), " ", -1

print 10
for i in range(0, 10):
    gen()


