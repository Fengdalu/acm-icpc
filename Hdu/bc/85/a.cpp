#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int vis[6000];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof (int) * (m + 1));
        vis[0] = true;
        int sum = 0;
        bool flag = false;
        for(int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            sum += x;
            if(sum >= m) {
                if(vis[sum % m]) flag = true;
            }
            vis[sum % m] = true;
        }
        if(flag) puts("YES"); else puts("NO");
    }
    return 0;
}
