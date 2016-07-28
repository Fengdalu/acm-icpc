

def run():
    i = 2
    k = 600851475143L
    while(i * i <= k):
        if(k % i == 0):
            print i
        while(k % i == 0):
            k = k / i
        i = i + 1

    print k

if(__name__ == '__main__'):
    run()
