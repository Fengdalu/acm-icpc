x = raw_input()
x = list(x)
for i in range(0, len(x)):
    x[i] = int(x[i])

for i in range(0, len(x)):
    if x[i] > 1:        
        for j in range(i, len(x)):
            x[j] = 1
        break

ans = 0
for i in range(0, len(x)):
    ans = ans * 2 + x[i]

print ans
print '\n'
       
    
