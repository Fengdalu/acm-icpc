#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
typedef pair<int, int> PII;

PII f[200010];
int c[200010];
int n, m;

bool check(int w) {
    int l = -1e9 - 1;
    for(int i = 0; i < n + m; i++) c[i] = false;
    for(int i = 0; i < n + m; i++)  {
        if(!f[i].BB) l = max(l, f[i].AA + w);
        else c[i] |= f[i].AA <= l;
    }
    int r = 1e9 + 1;
    for(int i = n + m - 1; i >= 0; i--) {
        if(!f[i].BB) r = min(r, f[i].AA - w);
        else c[i] |= f[i].AA >= r;
    }
    for(int i = 0; i < n + m; i++) if(f[i].BB && !c[i])  return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) f[i] = PII(i, 1);
    for(int i = 0; i < m; i++) f[i + n] = PII(i, 0);
    for(int i = 0; i < n; i++) scanf("%d", &f[i].AA);
    for(int i = 0; i < m; i++) scanf("%d", &f[i + n].AA);
    sort(f, f + n + m);
    long long l = 0, r = 2e9 + 1;
    while(l < r) {
        long long mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
