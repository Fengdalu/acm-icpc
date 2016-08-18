with open('2.asm', 'r') as f:
    print "int main(){"
    for line in f.readlines():
        print line
    print "return 0;}"
