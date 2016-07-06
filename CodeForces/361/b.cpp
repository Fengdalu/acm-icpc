#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

const int maxn = 200010;
int vis[maxn];
int f[maxn];
int a[maxn];
int n;

int main() {
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) a[i]--;
    priority_queue<pair<int, int> >q;
    for(int i = 0; i < n; i++) q.push(make_pair(-f[i], i));
    while(q.size()) {
        int x = q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        if(!vis[x + 1] && f[x + 1] > f[x] + 1) {
            f[x + 1] = f[x] + 1;
            q.push(make_pair(-f[x + 1], x + 1));
        }
       if(x > 0 && !vis[x - 1] && f[x - 1] > f[x] + 1) {
            f[x - 1] = f[x] + 1;
            q.push(make_pair(-f[x - 1], x - 1));
        }
       if(f[a[x]] > f[x] + 1) {
            f[a[x]] = f[x] + 1;
            q.push(make_pair(-f[a[x]], a[x]));
        }
    }
    for(int i = 0; i < n; i++) printf("%d ", f[i]);
    return 0;
}
