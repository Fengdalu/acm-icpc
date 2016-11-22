#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
ll u[maxn], s[maxn], f[maxn], w[maxn];
ll m[maxn], ss[maxn];
ll a[maxn], b[maxn];
ll tmp[maxn];
int n;
ll K;

int main() {
    scanf("%d%I64d", &n, &K);
    for(int i = 0; i < n; i++) scanf("%I64d", &u[i]);
    for(int i = 0; i < n; i++) scanf("%I64d", &s[i]);
    for(int i = 0; i < n; i++) f[i] = i, w[i] = s[i], m[i] = s[i];
    memset(b, 0x3f, sizeof b);
    for(int i = 0; i < n; i++)
        while(K) {
            if(K & 1) {
                for(int i = 0; i < n; i++) ss[i] += w[f[i]];
                for(int i = 0; i < n; i++) b[i] = min(b[i], m[f[i]]);
                for(int i = 0; i < n; i++) tmp[i] = f[i];
                for(int i = 0; i < n; i++) f[i] = u[tmp[i]];
            }
            K >>= 1;
            for(int i = 0; i < n; i++) tmp[i] = w[i];
            for(int i = 0; i < n; i++) w[i] += tmp[u[i]];
            for(int i = 0; i < n; i++) tmp[i] = m[i];
            for(int i = 0; i < n; i++) m[i] = min(m[i], tmp[u[i]]);
            for(int i = 0; i < n; i++) tmp[i] = u[i];
            for(int i = 0; i < n; i++) u[i] = tmp[u[i]];
        }
    for(int i = 0; i < n; i++) printf("%I64d %I64d\n", ss[i], b[i]);
    return 0;
}
