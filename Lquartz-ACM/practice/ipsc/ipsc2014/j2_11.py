def solve(N, M, edge_list, start, end):
    visited = [ False for i in range(N) ]
    dist = 1234567890
    for s, e in [ (start, end), (end, start) ]:
        # Currently processed vertex is u.
        u = s
        # The length of the path from s to u is curr_dist.
        curr_dist = 0
        while u != e:
            visited[u] = True
            # Finds the cheapest edge starting at u that leads to an unvisited vertex.
            best_edge = -1
            for k in range(M):
                p, q, w = edge_list[k]
                if p == u:
                    v = q
                elif q == u:
                    v = p
                else:
                    continue
                if visited[v]:
                    continue
                if best_edge == -1 or edge_list[best_edge][2] > w:
                    best_edge = k
            if best_edge == -1:
                break;
            p, q, w = edge_list[best_edge]
            # Update the currently processed vertex and the path length.
            if p == u: u = q
            else: u = p
            curr_dist += w
        if u == e:
            dist = min(dist, curr_dist)
    return dist
