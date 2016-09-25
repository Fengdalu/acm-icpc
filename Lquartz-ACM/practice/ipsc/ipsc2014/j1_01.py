def solve(n, k):
    if k == 0 or n == k: return 1
    return solve(n - 1, k) + solve(n - 1, k - 1)
