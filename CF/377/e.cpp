#include <bits/stdc++.h>

const int N = 1e6+10;
typedef std::pair<int, int> pii;
#define mp std::make_pair
#define AA first
#define BB second

std::map<int, std::queue<int> >f;
std::set<int> Q;
int p[N];
int a[N];
int u[N];
int ans[N];
bool vis[N];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", p + i);
    for(int i = 0; i < m; i++) scanf("%d", a + i);
    for(int i = 0; i < n; i++) f[p[i]].push(i), Q.insert(p[i]);

    int tot = 0, tot1 = 0;
    for(int k = 0; k < 32; k++) {
        for(int i = 0; i < m; i++) if(!vis[i]) {
            int K = k;
            int T = a[i];
            bool flag = false;
            while(K-- && !flag) {
                if((T + 1) / 2 == T) flag = true;
                T = (T + 1) / 2;
            }
            if(flag) continue;
            if(Q.find(T) == Q.end()) continue;
            if(f[T].size()) {
                tot++;
                tot1 += k;
                ans[f[T].front()] = i + 1;
                vis[i] = true;
                u[i] = k;
                f[T].pop();
                if(f[T].size() == 0) Q.erase(Q.find(T));
            }
        }
    }
    printf("%d %d\n", tot, tot1);
    for(int i = 0; i < m; i++) printf("%d ", u[i]); puts("");
    for(int i = 0; i < n; i++) printf("%d ", ans[i]);
    return 0;
}
