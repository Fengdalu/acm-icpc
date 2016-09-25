def solve(N, M, edge_list, start, end, magic = None):
    if magic is None: magic = N + 47 # this happens exactly once, at the very beginning
    result = 1234567890
    if magic == 1:
        for u,v,w in edge_list:
            if (u,v) == (start,end) or (v,u) == (start,end):
                result = w
        if start == end: result = 0
    else:
        for c in range(N):
            current  = solve( N, M, edge_list, start, c, magic // 2     )
            current += solve( N, M, edge_list, c,   end, (magic+1) // 2 )
            result = min(result, current)
    return result
