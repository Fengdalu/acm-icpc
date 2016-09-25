def solve(n, k):
    res = 1
    for i in range(n):     res = res *  (i + 1)
    for i in range(k):     res = res // (i + 1)
    for i in range(n - k): res = res // (i + 1)
    return res
