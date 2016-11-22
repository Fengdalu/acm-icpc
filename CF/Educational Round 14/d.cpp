#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000100];
int fa[1000010];

int get(int x) { if(fa[x] == x) return x; return fa[x] = get(fa[x]); }
vector<int>q[1000100];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        fa[get(x)] = get(y);
    }
    for(int i = 1; i <= n; i++) q[get(i)].push_back(a[i]);
    for(int i = 1; i <= n; i++)
    if(get(i) == i) { sort(q[i].begin(), q[i].end()); reverse(q[i].begin(), q[i].end()); }
    for(int i = 1; i <= n; i++) {
        printf("%d ", *q[get(i)].begin());
        q[get(i)].erase(q[get(i)].begin());
    }
    return 0;
}
