import heapq

def solve(N, M, edge_list, start, end):
    # Initialization of distances.
    infinity = 1234567890
    dist = [ infinity for i in range(N) ]
    dist[start] = 0

    priority_queue = [ (0, start) ]
    while len(priority_queue) > 0:
        d, u = heapq.heappop(priority_queue)
        for edge in edge_list:
            p, q, w = edge
            # Find an edge starting at u and save the other endpoint in v.
            if p == u:
                v = q
            elif q == u:
                v = p
            else:
                continue
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(priority_queue, (w, v))
    return dist[end]
