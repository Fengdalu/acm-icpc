#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000100;
pair<int, int> range[maxn];
long long sum[maxn];
int c[maxn];
int n, m, k;

inline int lowbit(int x) {return x & (-x); }
inline void insert(int x, int v) {
    while(x <= n) {
        c[x] += v;
        x += lowbit(x);
    }
}

inline int cal(int x) {
    long long tot =0;
    while(x > 0) {
        tot += c[x];
        x -= lowbit(x);
    }
    return tot;
}


int main() {
    while(~scanf("%d%d%d", &n, &k, &m)) {
        for(int i = 1; i <= n; i++){
            int x;
            scanf("%d", &x);
            sum[i] = sum[i - 1] + x;
        }
        for(int i = 0; i < m; i++) scanf("%d%d", &range[i].first, &range[i].second);
        sort(range, range + m);
        memset(c, 0, sizeof(int) * (n + 3));
        long long ans = 0;
        for(int i = 0; i < m; i++) {
            insert(range[i].first, 1);
            insert(range[i].second + 1, -1);
            int l = range[i].first, r = n;
            while(l < r) {
                int mid = (l + r + 1) / 2;
                if(cal(mid) < k) r = mid - 1;
                else l = mid;
            }
            if(cal(r) >= k) ans = max(ans, sum[r] - sum[range[i].first - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}

