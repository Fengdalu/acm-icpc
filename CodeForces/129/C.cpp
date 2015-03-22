#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define LL long long

LL pow(LL a, LL b)
{
    if(b <= 0) return 1LL;
    LL ans = 1;
    while(b)
    {
        if(b & 1) ans *= a;
        a *= a; b >>= 1;
    }
    return ans;
}

LL bit_count(LL x)
{
    LL ans = 0;
    while(x != 0) { ans++; x /= 10LL; }
    return ans;
}

LL cal1(int x)
{
    return 9LL * pow(10, x - 2);
}

char s[50];

LL find(LL x)
{
    if(x <= 9) return x;
    LL b = bit_count(x);
    LL ans = 0;
    for(int i = 1; i < b; i++) ans += cal1(i);
    memset(s, 0, sizeof s);
    sprintf(s, "%I64d", x);
    LL ans2 = 0;
    int len = strlen(s);
    for(LL i = 1; i <= 9; i++)
    if(pow(10, b - 1) * i + i <= x)
    {
        //cout << i << endl;
        LL p = 0;
        if(b == 2) { ans2 += 1; continue; }
        if(i < s[0] - '0')
        {
            ans2 = ans2 + pow(10, b - 2);
            continue;
        }
        for(int j = 1; j < len - 1; j++)
        {
            LL num = s[j] - '0';
            //cout << pow(10, b - 2 - j) << endl;
            p += num * pow(10, b - 2 - j);
        }
        p++;
        if(i > x % 10) p--;
        ans2 += p;
    }
    return ans + ans2;
}

int main()
{
    LL l, r;
    cin >> l >> r;
    cout << find(r) - find(l - 1) << endl;
    return 0;
}
