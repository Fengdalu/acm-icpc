#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PII;
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)

const int Maxn = 100010;
vector<int>G[Maxn];
LL sum[Maxn];
int cnt[Maxn];
set<PII>s;

int n;
LL c[Maxn];
LL ans[Maxn];


void dfs(int x, int fa) {
    for(int i = 0; i < G[x].size(); i++) if(G[x][i] != fa) {
        dfs(G[x][i], x);
    }

    if( cnt[x] != 0 ) {
        sum[cnt[x]] -= cnt[x] * c[x];
        s.erase( s.find(PII(cnt[x], x)) );
        cnt[x]--;
    }
    cnt[x]++;
    sum[cnt[x]] += cnt[x] * c[x];
    s.insert(PII(cnt[x], x));
    PII Q = *s.begin();
    ans[x] = sum[Q.AA];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
