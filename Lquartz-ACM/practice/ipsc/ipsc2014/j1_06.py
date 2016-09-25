def solve(n, k):
    A = [ 0 for i in range(n+1) ]
    for s in range(16**n):        # note: ** is exponentiation, e.g., 2**5 == 32
        tmp = s
        odd = 0
        for t in range(n):
            if tmp % 2: odd += 1  # note: % is modulo, e.g., 7 % 3 == 1
            tmp = tmp // 16       # note: // is integer division, e.g., 7 // 3 == 2
        A[odd] += 1
    return A[k] // 2**(3*n)
