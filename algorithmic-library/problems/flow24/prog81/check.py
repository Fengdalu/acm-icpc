from os import system as cmd

def check(data, file1, file2):
    fin = open(data, 'r')
    fp1 = open(file1, 'r')
    fp2 = open(file2, 'r')
    l3 = fin.readlines()
    edges = set()
    (m, n) = l3[0].strip().split(' ')
    n = int(n)
    m = int(m)
    for l in l3[1:]:
        (a, b) = l.strip().split(' ')
        a = int(a)
        b = int(b)
        edges.add((a, b))
    l1 = fp1.readlines()
    l2 = fp2.readlines()
    assert len(l1) == len(l2)
    assert l1[0].strip() == l2[0].strip()
    s1 = set()
    s2 = set()
    for l in l1[1:]:
        p, q = l.strip().split()
        p = int(p)
        q = int(q)
        assert not (p in s1)
        assert not (q in s2)
        s1.add(p)
        s2.add(q)
        assert (p, q) in edges

if(__name__ == '__main__'):
    cmd('g++ sol.cpp -o sol')
    for i in range(0, 11):
        cmd('./sol < ./test/air%d.in > sol.out' % i)
        check('./test/air%d.in' % i, './answer/air%d.out' % i, 'sol.out')
        print 'TEST %d OK' % i

    cmd('rm sol.out')
    cmd('rm sol')
