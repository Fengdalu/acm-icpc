#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 100010;
int c[maxn], w[maxn], f[maxn], p[maxn], v[maxn];
vector<int>q[maxn];
int vis[maxn];
int cmp(int a, int b) {
    return p[a] < p[b];
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &f[i], &p[i], &c[i], &w[i]);
        f[i]--;
        q[f[i]].push_back(i);
    }
    for(int i = 0; i < n; i++)
        sort(q[i].begin(), q[i].end(), cmp);
    long long ans = 0;
    for(int i = 0; i < n; i++)
    if(q[i].size()) ans += (long long)(w[i] - 1) * (p[q[i][0]] - c[i]);
    memset(vis, 0, sizeof vis);
    int cnt = 1;
    for(int i = 0; i < n; i++) if(!vis[i]) {
        int k = i;
        long long m = 1e9;
        bool flag = false;
        cnt++;
        while(!vis[k]) {
            vis[k] = cnt;

        }
    }
}
