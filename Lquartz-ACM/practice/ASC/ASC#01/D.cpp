#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 500 000
#define M 101000

int deg[N];
int u[M], v[M];
int n, m;
LL ans;

int main() {
    int i, j;
    int T;
    scanf("%d", & T);
    for(int Ca = 1; Ca <= T; Ca++) {
        scanf("%d%d", &n, &m);
        for(i = 1; i <= n; i++) deg[i] = 0;
        for(i = 1; i <= m; i++) {
            scanf("%d%d", &u[i], &v[i]);
            deg[u[i]]++; deg[v[i]]++;
        }
        ans = 0;
        for(i = 1; i<= m; i++) {
            ans += deg[u[i]];
            ans += deg[v[i]];
        }
        if(Ca > 1) cout << endl;
        cout << ans <<endl;
    }
}
