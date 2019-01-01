from collections import defaultdict

def run():
    fib = defaultdict(int)
    sum = 2
    fib[0] = 1
    fib[1] = 2
    t = 1
    while(fib[t] <= 4000000):
        t = t + 1
        fib[t] = fib[t - 1] + fib[t - 2]
        if(fib[t] & 1 == 0):
            sum = sum + fib[t]
    return sum

if(__name__ == "__main__"):
    print run()
