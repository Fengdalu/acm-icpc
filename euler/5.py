
def gcd(x, y):
    if(y == 0):
        return x
    return gcd(y, x % y)

def run():
    lcm = 1
    for i in xrange(1, 21):
        lcm = lcm * i / gcd(i, lcm)
    print lcm

if(__name__ == '__main__'):
    run()

