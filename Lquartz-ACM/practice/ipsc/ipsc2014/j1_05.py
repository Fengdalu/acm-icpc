def solve(n, k):
    if n < 0 or k < 0 or k > n: return 0
    if n == 0 or k == 0: return 1
    s = 0
    for t in range(1, 20): s += solve(n - t, k - 1)
    return s
