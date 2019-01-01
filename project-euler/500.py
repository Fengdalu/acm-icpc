from collections import defaultdict
import heapq
from codejamhelpers import primes

def run(limit=500500, mod=500500507):
    h = []
    for i in primes[:limit]:
        heapq.heappush(h, i)
    ans = 1
    for i in xrange(0, limit):
        t = heapq.heappop(h)
        heapq.heappush(h, t * t)
        ans *= t
        ans %= mod
    return ans

assert run(4) == 120

if(__name__ == '__main__'):
    print run()

