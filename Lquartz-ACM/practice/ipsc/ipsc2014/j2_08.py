def solve(N, M, edge_list, start, end):
    # Initialization of distances.
    infinity = 1234567890
    dist = [ infinity for i in range(N) ]
    dist[start] = 0

    for i in range(N - 2):
        for edge in edge_list:
            u, v, w = edge
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
            if dist[v] + w < dist[u]:
                dist[u] = dist[v] + w
    return dist[end]
