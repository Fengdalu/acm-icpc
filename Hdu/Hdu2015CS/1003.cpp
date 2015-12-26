#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define cmin(x, y) x = min(x, y)
int a[200000], b[200000];
int n, m;


int main() {
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < m; i++) scanf("%d", &b[i]);
        sort(b, b + m);
        LL tot = 0;
        for(int i = 0; i < n; i++) {
            int l = 0, r = m - 1;
            /*
            for(int k = 0; k < 50; k++) {
                int mid = (l + r) / 2;
                int midmid = (l + mid) / 2;
                if(abs(b[midmid] - a[i]) > abs(b[mid] - a[i])) l = midmid;
                else r = mid;
            }
            int ans = 100000;
            for(int j = l; j <= r; j++) cmin(ans, abs(a[i] - b[j]));
            */
            int p = lower_bound(b, b + m, a[i]) - b;
            int ans = 1200000;
            if(p != m) cmin(ans, abs(a[i] - b[p]));
            if(p) cmin(ans, abs(a[i] - b[p - 1]));
            tot += (LL)ans;
        }
        printf("%I64d\n", tot);
    }
    return 0;
}
