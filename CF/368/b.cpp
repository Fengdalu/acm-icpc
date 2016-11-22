#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N], b[N], c[N], n, m, k;
int vis[N];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    for(int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x); vis[x] = true;
    }
    int ans = -1;
    for(int i = 0; i < m; i++) {
        int x = a[i], y = b[i];
        if(vis[x] ^ vis[y]) {
            if(ans == -1 || c[i] < ans)  ans = c[i];
        }
    }
    cout << ans << endl;
    return 0;
}
