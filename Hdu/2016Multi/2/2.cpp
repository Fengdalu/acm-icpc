#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using std::cout;
using std::stack;
using std::vector;
using std::queue;
using std::pair;
using std::max;
using std::make_pair;
using std::endl;
#define AA first
#define BB second
#define cmin(x, y) x = min(x, y)
typedef unsigned int uint;
#define cmax(x, y) x = max(x, y)
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)

typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1e9 + 7;
vector<int>g[1 << 16];
char opt[10];
uint w[1 << 16];
uint d[1 << 8][1 << 8];
ll tot = 0;
pair<PII, uint>upd[1 << 16 | 1 << 8][1 << 8];
int cnt[1 << 17];
int op;

inline uint cal(uint a, uint b) {
    if(op == 0) return a & b;
    else if(op == 1) return a ^ b;
    return a | b;
}

void dfs(int rt) {
    cnt[rt] = 0;
    ll now = 0;
    for(int mk = 0; mk < 1 << 8; mk++) {
        uint x = cal(w[rt] >> 8, mk);
        uint y = w[rt] & 255;
        if(d[mk][y] == -1) continue;
        cmax(now, d[mk][y] + 1ll * (x << 8));
    }
    tot = tot + 1ll * (now + w[rt]) * (rt + 1) % mod;
    tot %= mod;
    for(uint mk = 0; mk < 1 << 8; mk++) {
        uint x = w[rt] >> 8;
        ll v = now + 1ll * cal(mk, w[rt] & 255);
        if(d[x][mk] == -1 || v > d[x][mk])  {
            upd[rt][cnt[rt]++] = (MP(MP(x, mk), d[x][mk]));
            d[x][mk] = v;
        }
    }
    for(auto &v: g[rt]) {
        dfs(v);
    }
    for(int i = 0; i < cnt[rt]; i++) {
        pair<PII, uint> t = upd[rt][i];
        uint x = t.AA.AA, y = t.AA.BB;
        ll c = t.BB;
        d[x][y] = c;
    }
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) {
        int n;
        scanf("%d%s", &n, opt);
        if(opt[0] == 'A') op = 0; else if(opt[0] == 'X') op = 1; else op = 2;
        for(int i = 0; i < n; i++) scanf("%u", &w[i]);
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 1; i < n; i++) {
            int p; scanf("%d", &p); p--;
            g[p].push_back(i);
        }
        memset(d, -1, sizeof d);
        tot = 0;
        dfs(0);
        cout << tot << endl;
    }
    return 0;
}

