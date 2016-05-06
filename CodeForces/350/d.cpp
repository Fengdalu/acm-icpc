#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

const int maxn = 100010;
int a[maxn], b[maxn];
pair<long long, int>q[maxn];
int n, w;
int main() {
    scanf("%d%d", &n, &w);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    long long ans = b[0] / a[0];
    long long tot = 0;
    for(int i = 0; i < n; i++) {
        ans = min(ans, (long long)b[i] / a[i]);
        tot += (long long)a[i];
        q[i] = make_pair(b[i] / a[i], i);
        b[i] %= a[i];
    }
    sort(q, q + n);
    long long s1 = 0, s2 = 0;
    for(int i = 0; i < n - 1 && w; i++) {
        int x = q[i].second;
        s1 += a[x];
        if(b[x] == 0) s2 += a[x];
        else s2 += a[x] - b[x];
        if(q[i].first != q[i + 1].first) {
            int l = q[i + 1].first - q[i].first;
            if(w < s2) { w = 0; break; }
            else {
                w -= s2;
                ans++;
                if(w < s1 * (l - 1)) { ans += w / s1;  w = 0; break;  }
                w -= s1 * (l - 1);
                s2 = s1;
                ans = q[i + 1].first;
            }
        }
    }
    w += b[n - 1];
    cout << ans + w / tot << endl;
}
