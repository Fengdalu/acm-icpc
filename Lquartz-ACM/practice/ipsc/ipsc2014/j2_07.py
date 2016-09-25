def prng_init(L): # initialize the pseudo-random number generator
    global prng_offset, prng_state
    prng_offset = 0
    prng_state = [ (i^(i>>3)) & 1 for i in range(7*L) ]

def prng_next(): # generate the next pseudo-random value
    global prng_offset, prng_state
    prng_offset += 7
    prng_state = prng_state[7:] + prng_state[:7] # cyclic rotation by 7

    if prng_offset % len(prng_state) == 0:
        i = 0
        while i < len(prng_state) and prng_state[i] > 0:
            prng_state[i] = 0
            i += 1
        if i < len(prng_state):
            prng_state[i] = 1

    answer = 0
    for i in range(7):
        answer = 2 * answer + prng_state[i]
    return answer

def solve(N, M, edge_list, start, end):
    prng_init(107)

    # Initialization of an adjacency matrix.
    infinity = 1234567890
    edges = [ [ infinity for j in range(N) ] for i in range(N) ]
    for i in range(N):
        edges[i][i] = 0

    # Entering edge lengths into the adjacency matrix.
    for edge in edge_list:
        u, v, w = edge
        edges[u][v] = edges[v][u] = w

    answer = infinity

    for attempt in range(107 * 2**749): # 107 * pow(2,749) should be enough, right?
        # generate a path
        path = [ prng_next() for i in range(100) ]
        # compute the total length along the path
        total = 0
        where = start
        for x in path:
            if x >= N: break
            total += edges[where][x]
            if x == end:
                answer = min(answer, total)
                break
            where = x
    
    return answer
