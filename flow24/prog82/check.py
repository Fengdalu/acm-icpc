from collections import defaultdict
from os import system as cmd


def check(data, file1, file2):
    f1 = open(data, 'r')
    f2 = open(file1, 'r')
    f3 = open(file2, 'r')

    value = defaultdict(int)
    relation = defaultdict(set)
    cost = defaultdict(int)

    lines = f1.readlines()
    (m, n) = lines[0].strip().split(' ')
    m = int(m)
    n = int(n)
    cur = 1
    for l in lines[1:1+m]:
        words = l.strip().split(' ')
        words = map(lambda x: int(x), words)
        value[cur] = words[0]
        for item in words[1:]:
            relation[cur].add(item)
        cur = cur + 1

    cur = 1
    for word in lines[m+1].strip().split(' '):
        cost[cur] = int(word)
        cur = cur + 1

    lines = f2.readlines()
    w = int(lines[2].strip())
    lines = f3.readlines()
    assert w == int(lines[2].strip())

    tot = 0
    tot1 = 0
    s = set()
    s1 = set()

    for p in lines[0].strip().split(' '):
        s.add(int(p))
        tot = tot + value[int(p)]
        assert int(p) <= m
    for it in lines[1].strip().split(' '):
        s1.add(int(it))
        tot1 = tot1 + cost[int(it)]
        assert int(it) <= n

    for p in s:
        for g in relation[p]:
            assert g in s1
    assert tot - tot1 == w

if(__name__ == '__main__'):
    cmd('g++ sol.cpp -o sol -O2')
    for i in range(0, 11):
        cmd('./sol < ./data/shut%d.in > data.out' % i)
        check('./data/shut%d.in' % i, './data/shut%d.out' % i, './data.out')
        print "TEST %d OK" % i
    cmd('rm sol data.out')
