#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Maxn 100100
int pre[Maxn];
int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i <= n; i++) {int x; scanf("%d", &x);pre[i] = pre[i - 1] + x;}
    int pos = 0, tot = 0;
    for(int i = 0; i < m; i++) {
        int t; scanf("%d", &t);
        t--;
        if(pos + (t - tot) >= n) { printf("%d\n", tot + (n - pos)); return 0; }
        pos += (t - tot);
        tot = t + 1;
        int l = 1, r = pos;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            int val = pre[pos] - pre[mid - 1];
            if(val <= k) r = mid - 1;
            else l = mid;
        }
        pos = l - 1;
    }
    printf("%d\n", tot + (n - pos)); return 0;
    return 0;
}