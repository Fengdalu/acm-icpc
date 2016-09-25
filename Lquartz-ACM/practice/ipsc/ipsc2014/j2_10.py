from Queue import Queue

def solve(N, M, edge_list, start, end):
    # Initialization.
    dist = [ 0 for i in range(N) ]
    visited = [ False for i in range(N) ]

    Q = Queue()
    Q.put(start)
    while not Q.empty():
        u = Q.get();
        for edge in edge_list:
            p, q, w = edge
            # Find an edge starting at u and save the other endpoint in v.
            if p == u:
                v = q
            elif q == u:
                v = p
            else:
                continue
            if not visited[v]:
                visited[v] = True
                dist[v] = dist[u] + w
                Q.put(v)
    return dist[end]
