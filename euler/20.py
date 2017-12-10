import math

sum = 1
N = 100
for i in range(1, N+1):
    sum *= i
ans = 0
while(sum != 0):
    (sum, mod) = divmod(sum, 10)
    ans += mod
print(ans)