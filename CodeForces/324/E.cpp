#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()
#define LL long long
#define PB(x) push_back(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define u32 unsigned int
#define N 3000

int num[N], a[N], b[N];
bool vis[N];
vector<PII>f;
vector<PII>ans;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    FORR(i, n) cin >> a[i];
    FORR(i, n) cin >> b[i];
    FORR(i, n) num[b[i]] = i;
    FORR(i, n) a[i] = num[a[i]];
    FORR(i, n) cout << a[i] <<" "; cout << endl;

    ans.clear();
    memset(vis, 0, sizeof vis);
    LL cnt = 0;
    FORR(i, n)
    if(!vis[i])
    {
        int k = i, t = k;
        f.clear();
        while(!vis[k]) { vis[k] = true; if(a[k] != k && !vis[a[k]]) { ans.PB(MP(t, a[k])); cnt += abs(a[k] - k); t = k; } k = a[k]; }
        if(f.SZ == 1) continue;
    }

    cout << cnt << endl << ans.SZ << endl;
    FOR(i, ans.SZ) cout << ans[i].AA << " " << ans[i].BB << endl;
    return 0;
}
