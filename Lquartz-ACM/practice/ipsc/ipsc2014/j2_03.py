def solve(N, M, edge_list, start, end):
    # Initalization.
    dist = 1234567890
    curr_dist = 0
    visited = [ False for i in range(N) ]

    vertex_stack = [] # note: an empty list, being used as an empty stack
    index_stack = []
    vertex_stack.append( (start, 0) )
    index_stack.append(0)
    visited[start] = True

    while len(vertex_stack) > 0:
        u, d = vertex_stack[-1]
        k = index_stack.pop()
        if u == end:
            dist = min(dist, curr_dist)
        while k < M:
            p, q, w = edge_list[k]
            # Find an edge starting at u and save the other endpoint in v.
            v = -1
            if p == u: v = q
            elif q == u: v = p

            if v >= 0 and not visited[v]:
                break
            else:
                k += 1

        if k == M:
            visited[u] = False
            vertex_stack.pop()
            if len(vertex_stack) > 0:
                curr_dist -= d
        else:
            index_stack.append(k + 1)
            vertex_stack.append((v, w))
            index_stack.append(0)
            visited[v] = True
            curr_dist += w
    return dist
