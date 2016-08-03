#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MP make_pair
#define AA first
#define BB second
#define PII pair<int, int>
const int N = 1000010 * 4;
const int mod = 1000000007;

int pk[N];
char a[N];
void manacher(int n)
{
    int mx = 0;
    int p;
    for(int i = 0; i < n; i++)
    {
        if(i < mx) pk[i] = min(pk[2 * p - i], mx - i);
        else pk[i] = 1;
        while(i + pk[i] < n && i - pk[i] > -1 && a[i + pk[i]] == a[i - pk[i]]) pk[i]++;
        if(i + pk[i] > mx) { p = i; mx = i + pk[i]; }
    }
}

int qpow(int x, int y) {
    int ans = 1;
    while(y) {
        ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

char s[N];
int c[N][2], add[N][2], f[N][2];

void update(int &a, int b) {
    a = (1l * a + 1ll * b + 1ll * mod) % mod;
}

int main() {
    while(~scanf("%s", s)) {
        int n = strlen(s);
        for(int i = 0; i <= 2 * n + 1; i++) a[i] = 0;
        for(int i = 0; i < n; i++) a[i * 2 + 1] = s[i];
        for(int i = 0; i <= n; i++) a[i * 2] = '#';
        int len = strlen(a);
        manacher(len);
        for(int i = 0; i < len; i++) c[i][0] = c[i][1] = add[i][0] = add[i][1] = 0;
        for(int i = 0; i < len; i++) {
            if(a[i] == '#' && pk[i] == 1) continue;
            int l, r;
            r = i + pk[i] - 2;
            l = i - pk[i] + 2;
            l = (l + 1) / 2;
            r = (r + 1) / 2;
            if(l > r) continue;
            int w = r - l + 1;
            int mid = (l + r) / 2;
            if(w & 1) {
                c[mid][0]++; update(add[mid][0], mid);
                c[r + 1][0]--; update(add[r + 1][0], -(l - 1));
                c[mid][1]++; update(add[mid][1], mid);
                c[l - 1][1]--; update(add[l - 1][1], -(r + 1));
            }
            else {
                c[mid + 1][0]++; update(add[mid + 1][0], mid);
                c[r + 1][0]--; update(add[r + 1][0], -(l - 1));
                c[mid][1]++; update(add[mid][1], mid + 1);
                c[l - 1][1]--; update(add[l - 1][1], -(r + 1));
            }
        }
        for(int i = 0; i < len; i++) f[i][0] = f[i][1] = 0;
        int cc = 0, tot = 0;

        for(int i = 1; i <= n; i++) f[i][0] = f[i][1] = 0;
        for(int i = 1; i <= n; i++) {
            update(tot, add[i][0]);
            f[i][0] = tot;
            update(cc, c[i][0]); update(tot, -cc);
        }
        cc = 0, tot = 0;
        for(int i = n; i >= 1; i--) {
            update(tot, add[i][1]);
            f[i][1] = tot;
            update(cc, c[i][1]); update(tot, cc);
        }
        int ans = 0;
        for(int i = 1; i < n; i++) update(ans, 1ll * f[i][0] * f[i + 1][1] % mod);
        cout << ans << endl;
    }
    return 0;
}
