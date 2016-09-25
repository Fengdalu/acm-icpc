def solve(n, k):
    if n == 0 or k == 0: return 1
    s = 0
    for i in range(k - 1, n): s += solve(i, k - 1) # note: range(x,y) returns [x,x+1,...,y-1]
    return s
