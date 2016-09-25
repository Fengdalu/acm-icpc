#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define Maxn 111111
char str[Maxn];
int cnt[300];
const LL MOD = 1000000007LL;
LL n, m;
LL ans;
vector<int> g;

int main() {
    int i, j, k, u, v, w;
    while(cin >> n) {
        cin >> str;
        memset(cnt, 0 , sizeof(cnt));
        for(i = 0; i < n; i++) {
            cnt[str[i]]++;
        }
        g.clear();
        g.PB(cnt['A']);
        g.PB(cnt['G']);
        g.PB(cnt['C']);
        g.PB(cnt['T']);
        sort(g.BG, g.ED);
        m = 0;
        for(i = g.size() - 1; i >= 0; i--) {
            if(g[i] == g[g.size() - 1]) m++;
        }
        ans = 1;
        for(i = 0; i < n; i++) {
            ans = ans * m % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}
