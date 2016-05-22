#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 8010;
int ans[maxn];
int sum[maxn];
int cnt[maxn * 4];
int a[maxn];
int n;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + int(a[i] > a[k]);
            for(int i = 0; i <= 4 * n; i++) cnt[i] = 0;
            for(int i = 1; i <= k; i++) {
                cnt[2 * sum[i - 1] - i + n]++;
            }
            int tot = 0;
            for(int j = k; j <= n; j++) tot += (cnt[2 * sum[j] - j + n]);
            if(k != n)printf("%d ", tot);
            else printf("%d", tot);
        }
        puts("");
    }
    return 0;
}
