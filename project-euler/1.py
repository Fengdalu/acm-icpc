def filter(x):
    if(x % 3 != 0 and x % 5 != 0):
        return 0
    return x

print reduce(lambda x, y: x + y, map(filter, range(1, 1000)))
