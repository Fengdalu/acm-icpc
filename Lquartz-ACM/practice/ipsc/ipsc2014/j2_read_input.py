from sys import stdin

# Reads the input in the following form:
# The first line of the input contains two integers N and M separated by
# a single space -- the number of vertices and the number of edges
# of the graph.
#
# Each of the following M lines contains three integers representing
# an edge of the graph. The integers are separated by a single space.
# The first two integers (in range between 0 and N-1, inclusive) denote
# the pair of vertices that are connected by the edge and the third integer
# denotes the edge length.
# The input graph does not contain loops and no edge is present in the
# list multiple times.
#
# The last line contains a pair of vertices (in range between 0 and N-1,
# inclusive) for which the shortest path is computed.

def read_input():
    # N = number of vertices in the graph
    # M = number of edges in the graph
    N, M = stdin.readline().split()
    N, M = int(N), int(M)

    # Read input into a list of tuples: (vertex1, vertex2, distance).
    edge_list = []
    for i in range(0, M):
        u, v, w = stdin.readline().split()
        u, v, w = int(u), int(v), int(w)
        edge_list.append((u, v, w))

    # Read the start and the end point of the shortest path.
    start, end = stdin.readline().split()
    start, end = int(start), int(end)

    return N, M, edge_list, start, end
