def solve(n, k):
    if k == 0 or n == k: return 1
    return solve(n, k + 1) * (k + 1) // (n - k)
