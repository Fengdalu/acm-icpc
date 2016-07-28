
def run():
    ans = -1
    for a in xrange(999, 99, -1):
        for b in xrange(999, 99, -1):
            s = str(a * b)
            q = list(s)
            q.reverse()
            if(s == ''.join(q)):
                ans = max(ans, a * b)
    print ans

if(__name__ == '__main__'):
    run()
