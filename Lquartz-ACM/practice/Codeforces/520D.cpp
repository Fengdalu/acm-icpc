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
const LL MOD = 1000000009;
set<int> S;
int n;
int used[Maxn];
vector<int> U[Maxn], D[Maxn];
vector<PII> pos;
map<PII, int> have;
LL ee[Maxn];
LL ans;

int getmust(int i) {
    int w = 0, cnt, j, v, k;
    for(j = 0; j < U[i].SZ; j++) {
        v = U[i][j];
        if(used[v]) continue;
        for(k = 0, cnt = 0; k < D[v].SZ; k++) {
            if(!used[D[v][k]]) cnt++;
        }
        if(cnt == 1) w++;
    }
    return w;
}

int main() {
    int i, j, k, u, v, w;
    while(cin >> n) {
        ee[0] = 1;
        for(i = 1; i <= n; i++) ee[i] = ee[i - 1] * n % MOD;
        pos.clear();
        S.clear();
        have.clear();
        for(i = 0; i < n; i++) {
            scanf("%d%d", &u, &v);
            pos.PB(MP(u, v));
            have[MP(u, v)] = i;
        }
        for(i = 0; i < n; i++) {
            used[i] = 0;
            U[i].clear();
            D[i].clear();
        }
        for(i = 0; i < n; i++) {
            for(j = -1; j <= 1; j++) {
                u = pos[i].AA + j; v = pos[i].BB - 1;
                if(have.ED == have.find(MP(u, v))) continue;
                w = have[MP(u, v)];
                //cout << "adde " << w << " " << i << endl;
                U[w].PB(i);
                D[i].PB(w);
            }
        }
        for(i = 0; i < n; i++) {
            w = getmust(i);
            if(w == 0) {
                S.insert(i);
                //cout << "insert " << i << endl;
            }
        }
        ans = 0;
        for(int ii = 0; ii < n; ii++) {
            if((ii & 1) == 0) {
                w = *(--S.ED);
                S.erase(w);
            }
            else {
                w = *(S.BG);
                S.erase(w);
            }
            used[w] = 1;
            //cout << "used " << w << endl;
            ans = (ans + w * ee[n - 1 - ii]) % MOD;
            //cout << ee[n - 1 - ii] << endl;
            //cout << "ans " << ans << endl;
            for(i = 0; i < U[w].SZ; i++) {
                u = U[w][i];
                if(getmust(u) == 0 && !used[u]) {
                    S.insert(u);
                }
                else {
                    S.erase(u);
                }
                for(k = 0; k < D[u].SZ; k++) {
                    if(getmust(D[u][k]) == 0 && !used[D[u][k]]) {
                        S.insert(D[u][k]);
                    }
                    else {
                        S.erase(D[u][k]);
                    }
                }

            }
            for(i = 0; i < D[w].SZ; i++) {
                u = D[w][i];
                if(getmust(u) == 0 && !used[u]) S.insert(u);
            }
        }
        cout << ans % MOD << endl;
    }

    return 0;
}
