s = raw_input()
a = raw_input()
b = raw_input()

f1 = False
f2 = False


p1 = s.find(a)
if(p1 != -1):
    p2 = s.find(b, p1 + len(a))
    if p2 != -1:
        f1 = True

s = list(s)
s.reverse()
s = ''.join(s)

p1 = s.find(a)
if(p1 != -1):
    p2 = s.find(b, p1 + len(a))
    if p2 != -1:
        f2 = True

if f1 and f2:
    print 'both'
elif f1:
    print 'forward'
elif f2:
    print 'backward'
else:
    print 'fantasy'
print '\n'
    
    




    
