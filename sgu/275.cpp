#include <cstdio>
#include <iostream>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
int a[61][110];
int m;

int main() {
    scanf("%d", &m);
    int n = 60;
    for(int i = 0; i < m; i++) {
        ll x;
        scanf("%lld", &x);
        for(int j = 0; j <= 60; j++)
            a[j][i] = ((x >> (60 - j)) & 1);
    }
    for(int i = 0; i <= 60; i++) a[i][m] = 1;
    ll ans = 0;
    ll p = 1LL << 60;

    for(int i = 0; i <= 60; i++) {
        int x = -1;
        for(int j = 0; j < m; j++)
            if(a[i][j]) {
                x = j;
                break;
            }
        if(x == -1 && a[i][m] == 0) ans += p;
        else if(x != -1)  {
            ans += p;
            for(int j = i + 1; j <= 60; j++)
                if(a[j][x])
                    for(int k = 0; k <= m; k++)
                        a[j][k] ^= a[i][k];
        }
        p >>= 1;
    }
    cout << ans << endl;
    return 0;
}
