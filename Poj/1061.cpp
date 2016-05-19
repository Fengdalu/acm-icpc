#include <iostream>
#include <cmath>

using namespace std;

__int64 gcd(__int64 a, __int64 b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

void extend(__int64 a, __int64 b, __int64 &x, __int64 &y)
{
    if (b == 0) {x = 1; y = 0;return;}
    extend(b, a % b, x, y);
    
    int t = x;
    x = y;
    y = t - (a / b) * y;
}

int main()
{
    __int64 x, y, n, m, l;
    while (cin>> x >> y >> m >> n >> l)
    {
        __int64 a = n - m;
        __int64 b = l;
        __int64 c = x - y;
        __int64 k1;
        __int64 k2;
        
        int r = gcd(a, b);
        if (c % r)
        {
            cout << "Impossible" << endl;
            continue;
        }
        
        a /= r;
        b /= r;
        c /= r;
        
        extend(a, b, k1, k2);
        
        int t = c * k1 / b;
        int ans = k1 * c - t * b;
        while (ans < 0) ans += b;
        cout << ans << endl;  
    }
    return 0;
}